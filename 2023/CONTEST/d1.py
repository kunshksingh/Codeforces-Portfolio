import sys
import math
import heapq
import collections
# import bitarray
input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
def solution():
    length = int(input())
    nums = list(map(int, input().split()))
    increments = collections.defaultdict(int)
    if (sum(nums) % length == 0):
        target = sum(nums) // length
        for i in nums:
            diff = i-target
            if diff >= 0:
                increments[diff] += 1
            else:
                increments[diff] -= 1
        increments[0] = 0
        if (max(increments.values()) > 1):
            print("NO")
        else:
            print("YES")


    else:
        print("NO")


for i in range(testcases):
    solution()