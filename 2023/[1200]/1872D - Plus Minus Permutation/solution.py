import sys
import math
import heapq
import collections
input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())

def solution():
    n, x, y = map(int, input().split())
    x_occur = n//x
    y_occur = n//y
    overlaps = n//math.lcm(x,y)
    def pascalNums(n,m):
        return ((m)*(m+1))//2 - ((n+1)*(n))//2

    x_1 = pascalNums(n-(x_occur - overlaps),n)
    x_2 = pascalNums(0,(y_occur - overlaps))
    print( x_1 - x_2)


for i in range(testcases):
    solution()