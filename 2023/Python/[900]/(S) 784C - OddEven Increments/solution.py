import sys
import math
import heapq
import collections
input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
def solution():
    length = int(input())
    nums = list(map(int, input().split()))
    odds = nums[1]%2
    evens = nums[0]%2 
    for i in range(length):
        if (i%2 == 0):
            if nums[i]%2 != evens:
                    return False
        else:
            if nums[i]%2 != odds :
                return False

    return True

for i in range(testcases):
    if(solution()):
        print("Yes")
    else:
        print("No")