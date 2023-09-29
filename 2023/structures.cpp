/*
FAST INVERSE — FOR CPP LARGE DIVISON WITH MODULO


long long fast_inv(long long base, long long exp, long long modulo){
    long long res = 1;
    long long cur = base;
    while (exp > 0){
        if (exp % 2 == 1){
            res = (res * cur) % modulo;
        }
        cur = (cur * cur) % modulo;
        exp /= 2;
    }
    return res;
}


MOD INT

template<const int MOD>
struct modint{
    int val;
    modint() {val = 0;}
    modint(const long long& v){
        val = v % MOD;
        if(val < 0) val += MOD;
    }

    friend ostream& operator<<(ostream& os, const modint& a){return os << a.val;}
    friend bool operator==(const modint& a, const modint& b){return a.val == b.val;}
    friend bool operator!=(const modint& a, const modint& b){return !(a == b);}
    friend bool operator<(const modint& a, const modint& b){return a.val < b.val;}

    modint operator-() const {return modint(-val);}
    modint& operator+=(const modint& other){
        val += other.val;
        if(val >= MOD) val -= MOD;
        return this;
    }
    modint& operator-=(const modint& other){
        val -= other.val;
        if(val < 0) val += MOD;
        returnthis;
    }
    modint& operator=(const modint& other){
        val = (int)((1LL val * other.val) % MOD);
        return this;
    }
    modint& operator++(){
        val++;
        if(val == MOD) val = 0;
        returnthis;
    }
    modint& operator--(){
        if(val == 0) val = MOD;
        val--;
        return this;
    }
    friend modint modpow(modint a, long long p){
        modint res = 1;
        for(; p; p >>= 1, a= a){
            if(p & 1) res = a;
        }
        return res;
    }
    friend modint inv(const modint& a){return modpow(a, MOD - 2);}
    modint& operator/=(const modint& other){return (this) = inv(other);}

    friend modint operator+(modint a, const modint& b){return a += b;}
    friend modint operator-(modint a, const modint& b){return a -= b;}
    friend modint operator(modint a, const modint& b){return a *= b;}
    friend modint operator/(modint a, const modint& b){return a /= b;}
    friend modint operator++(modint& a, int){modint r = a; ++a; return r;}
    friend modint operator--(modint& a, int){modint r = a; --a; return r;}

    operator long long() const{return val;}
};


*/