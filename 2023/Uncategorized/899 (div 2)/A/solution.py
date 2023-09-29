import sys
import math
import heapq
import collections
# import numpy as np
# from numpy.fft import fft, ifft

input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
def solution():
    n = int(input())
    s_0, e_0 = map(int, input().split())
    for i in range(1,n):
        s_i, e_i = map(int, input().split())
        if (s_0 <= s_i and e_0 <= e_i):
            print(-1)
            return
    print(s_0)


for i in range(testcases):
    solution()