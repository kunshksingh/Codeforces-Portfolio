import sys
import math
import heapq
import collections
# import numpy as np
# from numpy.fft import fft, ifft

input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
def solution():
    n, x = map(int, input().split())
    init_x = x
    coral = list(map(int, input().split()))
    coral.sort()
    h = 1

    x -= (n * max(coral)-sum(coral))
    h = max(coral)

    if x > 0:
        h += x//n
    elif x < 0 :
        x = init_x
        h = 1
        equal = 0
        prev = coral[0]
        more = 0
        for j in range(1,len(coral)):
            h = coral[j]
            if (h == prev):
                equal += 1
            else:
    
                more += (equal+1)
                equal = 0
                x -= more * (coral[j]-prev)
                prev = coral[j]
                if (x < 0): 
                    break
        h += x//j
        

    print(h) 


for i in range(testcases):
    solution()