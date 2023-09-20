import sys
import math
import heapq
import collections
# import numpy as np
# from numpy.fft import fft, ifft

input = sys.stdin.readline # Don't forget to rstrip()


def solution():
    N = int(input())

    minimum_squares = N
    for i in range(int(math.sqrt(N)),int(math.sqrt(N))+int(math.sqrt(N))//2+1):
        minimum_squares = min(minimum_squares, (i*((N+i-1)//i) - N))
      
    print(minimum_squares)
    



solution()