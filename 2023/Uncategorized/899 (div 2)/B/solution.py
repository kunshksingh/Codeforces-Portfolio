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
    top = list(map(int, input().split()))
    left = list(map(int, input().split()))
    top.sort()
    left.sort()
    t = 0
    l = 0
    for i in range(len(top)):
        t += (top[i] + left[0])
    for i in range(len(left)):
        l += (left[i] + top[0])

    print(min(t,l))



for i in range(testcases):
    solution()