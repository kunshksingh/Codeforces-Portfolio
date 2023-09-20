import sys
import math
import heapq
import collections
# import numpy as np
# from numpy.fft import fft, ifft
input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
def solution():
    n,m = map(int, input().split())
    a = []
    for _ in range(n):
        a.append(list(map(int, input().split())))

    for i in range(n):
        for j in range(m):
            if (i+j) % 2 != a[i][j] % 2: 
                a[i][j] += 1
    for row in a:
        print(' '.join([str(x) for x in row]))


for i in range(testcases):
    solution()