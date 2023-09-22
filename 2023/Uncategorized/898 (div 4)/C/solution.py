import sys
import math
import heapq
import collections
# import numpy as np
# from numpy.fft import fft, ifft

input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
def solution():
    targetVal = 1
    points = 0
    for i in range(1,11):
        row = str(input()).rstrip()
        for j in range(10):
            z = j+1
            if row[j] == "X":
                points += int(i >=5 and i <= 6 and z >= 5 and z <= 6) + int (i >= 4 and i<= 7 and z >= 4 and z <= 7) + int (i >= 3 and i<= 8 and z>= 3 and z <= 8) + int (i >= 2 and i<= 9 and z >= 2 and z <= 9) + int (i >= 1 and i<= 10 and z >= 1 and z <= 10)
    print(points)
for i in range(testcases):
    solution()