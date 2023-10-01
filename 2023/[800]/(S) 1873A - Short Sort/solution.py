import sys
import math
import heapq
import collections
# import numpy as np
# from numpy.fft import fft, ifft

input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
def solution():
    cards = str(input())
    if cards.find("a") == 0 or cards.find("b") == 1 or cards.find("c") == 2: 
        print("YES")
    else:
        print("NO")

for i in range(testcases):
    solution()