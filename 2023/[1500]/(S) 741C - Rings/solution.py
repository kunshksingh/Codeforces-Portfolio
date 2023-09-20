import sys
import math
import heapq
import collections
input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())

def solution():
    n = int(input())
    rings = input().rstrip()
    window = n//2

   
    for i in range(n):
        if rings[i] == '0':
            if i < window: 
              #If we have a 0 on the left side, we can simply use the same number twice
              return i + 2, n, i+1, n
            else:
              #If there is a 0 on the right side or middle, adding the 0 to the end of any binary string doubles it
              return 1, i+1, 1, i
    # If there are no 0s in the string, it must be all ones — 
    # for all 1 bitstrings length n where n % 2 == 0, 
    # a length 2n of 1s is divisible by length n of 1s
    return 1, 2*window, 1, window       

for i in range(testcases):
    print(" ".join(map(str, solution())))