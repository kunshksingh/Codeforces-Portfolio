import sys
import math
import heapq
import collections
input = sys.stdin.readline # Don't forget to rstrip()



def fast_pow(base, exp, modulo):
    res = 1
    cur = base
    while exp > 0:
        if exp % 2 == 1:
            res = (res * cur) % modulo
        cur = (cur * cur) % modulo
        exp //= 2
    return res
def get_degree(n, p):
    degree = 0
    u = p
    temp = n
    while u <= temp:
        degree += temp // u
        u *= p
    return degree

num = 1
factorial = {}
factorial[0] = 1
M = ((10**9)+7)
for i in range(1,10**6+1):
    num = (num * i) % M
    factorial[i] = num
    factorial[-i] = 1/num
    


def choose(n,k,m) -> int:
    return (factorial[n] * fast_pow(factorial[k], m-2, m) * fast_pow(factorial[n-k], m-2, m)) % m
def count_paths(N, X, Y):
    count = 0

    y_counts = [0 for _ in range(0,(N//Y)+1)]
    for k in range(1, (N//Y)+1):
        y_counts[k] = choose(N-(Y*(k))+(k-1), k-1, M) 


    x_count = [0 for _ in range(0,(N//X)+1)]
    for k in range(1, min((N//X)+1,len(y_counts))): 
        x_count[k] = (choose((N-X*(k))+(k-1), k-1,M) * y_counts[k]) 

    return sum(x_count)


def solution():
    n, x, y = map(int, input().split())
    combos = count_paths(n,x,y)
    print(combos % M)
solution()