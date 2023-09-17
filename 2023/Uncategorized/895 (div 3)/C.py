import sys
import math
import heapq
import collections
input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())

def divisor(n):
  if n <= 1:
    return 1
  for i in range(2, int(math.sqrt(n))+1):
    if n % i == 0:
      return i
  return 1

def solution():
    l, r = map(int, input().split())
    diff = r-l
    if l <= 100 and r <= 100:
        for i in range(1,r):
            for j in range(1,r):
                if ( i+j < l or i+j > r):
                   continue
                if (math.gcd(i,j) != 1 and i + j >= l and i + j <= r):
                    return i,j
    else:
        # if (diff >= 1):
        #    for i in range(l, l+2):
        #       if i%2 == 0:
        #         return i-2, 2
        for i in range(l,r+1):
            # for j in range(0,r-1):
            #     if ( i+j < l or i+j > r):
            #        continue
            d = divisor(i)
            if d > 1:
                return (i-d) , d
    
    return -1

for i in range(testcases):
    tuplet = solution()
    if type(tuplet) == int:
        print(tuplet)
    else:
        print(tuplet[0], tuplet[1])