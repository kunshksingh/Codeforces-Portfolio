import sys
import math
import heapq
import collections
input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
def solution():
    numTraps = int(input())
    traps = []
    for i in range(numTraps):
        traps.append(tuple(map(int, input().split())))
    
    # traps = sorted(traps, key=lambda x : x[0])
    maxTravelDistance = min([traps[i][0] + ((traps[i][1]-1)//2) for i in range (len(traps))])
    print(maxTravelDistance)

for i in range(testcases):
    solution()