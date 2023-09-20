import sys
import math
import heapq
import collections
input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())

pascalNum = 0
pascalNums = {1:0}
for i in range (1, 100000):
    pascalNum += i
    pascalNums[i+1] = pascalNum


def solution():
    length = int(input())
    nums = list(map(int, input().split()))
    nums = [math.floor(math.log(num,2)) for num in nums]
    counter_nums = collections.Counter(nums).values()

    print(sum([pascalNums[x] for x in counter_nums]))

for i in range(testcases):
    solution()