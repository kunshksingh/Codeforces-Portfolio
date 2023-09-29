import sys
import math
import heapq
import collections
# import numpy as np
# from numpy.fft import fft, ifft

input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
def solution():
    bitstring = str(input()).rstrip()
    bitmask = "10"*(len(bitstring)//2) + "1" * int(len(bitstring) % 2 == 1)
    bitmask2 = "01"*(len(bitstring)//2) + "0" * int(len(bitstring) % 2 == 1)
    counter = 0

    print(bitstring)
    counter2 = 0
    length = 0
    while(bitstring > 0):
        if 1 & alt1:
            counter += 1
        if 2 & alt2:
            counter += 1
        alt1 >>= 1
        alt2 >>= 1
        length += 1
    print(counter % 998244353)

for i in range(testcases):
    solution()