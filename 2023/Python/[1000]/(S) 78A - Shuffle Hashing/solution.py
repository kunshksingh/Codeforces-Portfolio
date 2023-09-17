import sys
import math
import heapq
import collections
input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
def solution():
    p = str(input()).rstrip()
    h = str(input()).rstrip()
    password = collections.Counter(p)
    stack = collections.Counter(h[0:len(p)])
    for l in set(stack):
         if password[l] == 0:
              password[l] = 0
    vool = True
    for i in range(len(p),len(h)):
        if (password == stack):
            print("YES")
            vool = False
            break
        stack[h[i]] += 1
        stack[h[i-len(p)]] -= 1
        if password[h[i]] == 0:
              password[h[i]] = 0
    
    if (password == stack and vool):
                print("YES")
                vool = False
    if (vool):
        print("NO")

for i in range(testcases):
    solution()