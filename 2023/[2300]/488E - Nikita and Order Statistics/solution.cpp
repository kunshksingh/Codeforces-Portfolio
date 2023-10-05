
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <chrono>
#include <random>
#include <climits>

using namespace std;
//faster FFT implementation

//use multiply(a, b) to multiply two polynomials a and b
//the higher power coefficients have the lower index in the vectors
//a= [ a(n-1) , a(n-2) , a(n-3) , ............a(0) ]
//the multiply function will return a vector of long long
//If mod is different just change the value of prime

const int prime = 988244353;
//Implementation of FFT (Taken from https://github.com/jaehyunp/stanfordacm/blob/master/code/FFT.cc)

//2^ceil(log2(x)) where x = Maximum size of Polynomial
const int MAX = 131100;

//Complex class: Quite faster than in-built C++ library as it uses only functions required
template<typename T> class cmplx {
private:
	T x, y;
public:
	cmplx () : x(0.0), y(0.0) {}
	cmplx (T a) : x(a), y(0.0) {}
	cmplx (T a, T b) : x(a), y(b) {}
	T get_real() { return this->x; }
	T get_img() { return this->y; }
	cmplx conj() { return cmplx(this->x, -(this->y)); }
	cmplx operator = (const cmplx& a) { this->x = a.x; this->y = a.y; return *this; }
	cmplx operator + (const cmplx& b) { return cmplx(this->x + b.x, this->y + b.y); }
	cmplx operator - (const cmplx& b) { return cmplx(this->x - b.x, this->y - b.y); }
	cmplx operator * (const T& num) { return cmplx(this->x * num, this->y * num); }
	cmplx operator / (const T& num) { return cmplx(this->x / num, this->y / num); }
	cmplx operator * (const cmplx& b) {
		return cmplx(this->x * b.x - this->y * b.y, this->y * b.x + this->x * b.y);
	}
	cmplx operator / (const cmplx& b) {
		cmplx temp(b.x, -b.y); cmplx n = (*this) * temp;
		return n / (b.x * b.x + b.y * b.y);
	}
};

//T = int/long long as per polynomial coefficients
//S = double/long double as per precision required
template<typename T, typename S> struct FFT {
	S PI;
	int n, L, *rev, last;
	cmplx<S> ONE, ZERO;
	cmplx<S> *omega_powers;

	FFT() {
		PI = acos(-1.0);
		ONE = cmplx<S>(1.0, 0.0);
		ZERO = cmplx<S>(0.0, 0.0);
		last = -1;
		int req = 1 << (32 - __builtin_clz(MAX));
		rev = new int[req];
		omega_powers = new cmplx<S>[req];
	}

	~FFT() {
		delete rev;
		delete omega_powers;
	}

	void ReverseBits() {
		if (n != last) {
			for (int i = 1, j = 0; i < n; ++i) {
				int bit = n >> 1;
				for (; j >= bit; bit >>= 1) j -= bit;
				j += bit;
				rev[i] = j;
			}
		}
	}

	void DFT(vector<cmplx<S> > &A, bool inverse = false) {
		for(int i = 0; i < n; ++i)
			if (rev[i] > i) swap(A[i], A[rev[i]]);
		for (int s = 1; s <= L; s++) {
			int m = 1 << s, half = m / 2;
			cmplx<S> wm(cosl(2.0 * PI / m), sinl(2.0 * PI / m));
			if (inverse) wm = ONE / wm;
			omega_powers[0] = ONE;
			for(int k = 1; k < half; ++k) {
				omega_powers[k] = omega_powers[k-1] * wm;
			}
			for (int k = 0; k < n; k += m) {
				for (int j = 0; j < half; j++) {
					cmplx<S> t = omega_powers[j] * A[k + j + half];
					cmplx<S> u = A[k + j];
					A[k + j] = u + t;
					A[k + j + half] = u - t;
				}
			}
		}
		if (inverse) {
			for (int i = 0; i < n; i++) A[i] = A[i] / n;
		}
	}

	// c[k] = sum_{i=0}^k a[i] b[k-i]
	vector<T> multiply(const vector<T> &a, const vector<T> &b) {
		L = 0;
		int sa = a.size(), sb = b.size(), sc = sa + sb - 1;
		while ((1 << L) < sc) L++;
		n = 1 << L;
		ReverseBits();
		last = n;
		vector<cmplx<S> > aa(n, ZERO), bb(n, ZERO), cc;
		for (int i = 0; i < sa; ++i) aa[i] = cmplx<S>(a[i], 0);
		for (int i = 0; i < sb; ++i) bb[i] = cmplx<S>(b[i], 0);
		DFT(aa, false); DFT(bb, false);
		for (int i = 0; i < n; ++i) cc.push_back(aa[i] * bb[i]);
		DFT(cc, true);
		vector<T> ans(sc);
		for (int i = 0; i < sc; ++i) ans[i] = cc[i].get_real() + 0.5;
		return ans;
	}

	// c[k] = sum_{i=0}^k a[i] a[k-i], saves one FFT call
	vector<T> multiply(const vector<T> &a) {
		L = 0;
		int sa = a.size(), sc = sa + sa - 1;
		while ((1 << L) < sc) L++;
		n = 1 << L;
		ReverseBits();
		last = n;
		vector<cmplx<S> > aa(n, ZERO), cc;
		for (int i = 0; i < sa; ++i) aa[i] = cmplx<S>(a[i], 0);
		DFT(aa, false);
		for (int i = 0; i < n; ++i) cc.push_back(aa[i] * aa[i]);
		DFT(cc, true);
		vector<T> ans(sc);
		for (int i = 0; i < sc; ++i) ans[i] = cc[i].get_real() + 0.5;
		return ans;
	}
};

#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define rep(a, b) for(int i = a; i < (b); ++i)
#define rep2(b) for(int i = 0; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)

#define println(x) cout << x << endl;
#define print(x) cout << x << " ";
#define printv(x) rep2(x.size()) cout<<x[i]<<" "; cout<<endl;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

void solve(){
    int n, x;
    cin >> n >> x;
    vl y(n+1);
    vl z(n+1);
    y[0]=0;
    z[0]=1;
    rep(1,n+1){
        cin >> y[i]; 
        if (y[i] > x){ y[i] = 0;
        } else y[i] = 1;
        if (y[i] == 0){ z[i] = 1;
        } else z[i] = 0;
    }
    printv(y);
    printv(z);
    
    FFT<ll, ld> fft;
    vl res = fft.multiply(y,z);
    printv(res);
    vl res2 = fft.multiply(res,y);
    printv(res2);
    // cout << 1 << endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15)<<fixed;
    int t=1;
    // cin >> t;
    for (int c = 0; c < t; c++)
    {   
        // cout<<"Case #"<<c+1<<": ";
        solve();
    }
}
//usage example
// NTT<int, prime, root, 18> ntt;

// Usage fftMod<int, 998244353, -1, 23> // g = 3
//       fftMod<int, 1004535809, -1, 19> fft; // g = 3
//       fftMod<int, 469762049, -1, 26> // g = 3
//       fftMod<li, 10000093151233, -1, 26> // g = 5
//       fftMod<li, 1000000523862017, -1, 26> // g = 3
//       fftMod<li, 1000000000949747713, -1, 26> // g = 2
//       fftMod<li, -1, li(1e13), 20>