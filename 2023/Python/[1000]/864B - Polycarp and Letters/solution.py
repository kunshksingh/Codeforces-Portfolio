import sys
import math
import heapq
import collections

input = sys.stdin.readline # Don't forget to rstrip()


def solution():
    length = int(input())
    word = str(input()).rstrip()
    w_ords = [ord(i) for i in word]
    if max(w_ords) < 97 : # no lowercase letters
        return 0
    maxLen =0    
    tempSet = set()
    for i in range(len(w_ords)):
        if w_ords[i] >=  97:
            tempSet.add(w_ords[i])
        else:
            maxLen = max(maxLen, len(tempSet))
            tempSet = set()

    return max(maxLen,len(tempSet))

print(solution())