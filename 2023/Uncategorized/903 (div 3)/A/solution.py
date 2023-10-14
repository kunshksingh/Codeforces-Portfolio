import math 
import sys

t = int(input())
input = sys.stdin.readline # Don't forget to rstrip()

def solution():
        n,m,s,s2 = 0,0,0,0
        n,m = map(int, input().split())
        s = str(input()).rstrip()
        s2 = str(input()).rstrip()

        for i in range(7):
            if (s.find(s2) != -1):
                print(i)
                return
            
            s *= 2
        print(-1)

for _ in range(t):
    solution()

#   rep2((int)ceil(log2(s.length()/s2.length()))){
    #     s = s+s;
    # }
    # cout << 
    # if (s.find(s2) != string::npos) {
    #     println((int)ceil(log2(s.length()/s2.length())));
    # }
    # println(-1);
