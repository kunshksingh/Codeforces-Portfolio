import sys
import math
import heapq
import collections
input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
def solution():
    n,m,q = map(int, input().split())
    i = 0
    p = max(n,m)
    s = min(n,m)
    while (p > s):
        p -= q
        s += q
        i+=1
    # if n == m:
    #     print(0)
    #     return
    # print((abs(n-m)//(q*2)))
    print(i)


for i in range(testcases):
    solution()