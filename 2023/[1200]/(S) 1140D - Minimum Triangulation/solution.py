import sys
import math
import heapq
import collections
# import numpy as np
# from numpy.fft import fft, ifft

input = sys.stdin.readline # Don't forget to rstrip()


def solution():
    n = int(input())
    # if n == 3:
    #     print(6)
    #     return 
    # if n == 4:
    #     print(18)
    #     return
    n_triangles = n-2
    triangles = 0
    triangular = 0
    mustBreak = False
    for i in range(1, n):
        for j in range(i+1,n):
            triangular += i*j*(j+1)
            triangles += 1
            if triangles == n_triangles:
                mustBreak = True
                break
            
        if (mustBreak):
            break
    print(triangular)


# for i in range(testcases):
solution()