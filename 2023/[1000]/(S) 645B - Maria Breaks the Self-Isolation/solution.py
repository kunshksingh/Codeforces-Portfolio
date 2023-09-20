import sys
import math
import heapq
import collections
input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
def solution():
    n = int(input())
    grannies = list(map(int, input().split()))
    c = 1
    grannies.sort()
    granny_subset = []
    for granny in grannies:
        if granny <= c:
            c += 1
        else:
            granny_subset.append(granny)
        
        if len(granny_subset) > 0 and granny-len(granny_subset) < c:
            c += len(granny_subset)
            granny_subset = []
        
    print(c)



for i in range(testcases):
    solution()