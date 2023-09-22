import sys
import math
import heapq
import collections
# import numpy as np
# from numpy.fft import fft, ifft

input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
def solution():
    n,k = map(int, input().split())
    paper = str(input()).rstrip()
    i = 0
    erases = 0
    while (i < len(paper)):     
        if paper[i] == "B":
            i += k
            erases += 1
        else:
            i += 1
    print(erases)

            

for i in range(testcases):
    solution()