import sys
import math
input = sys.stdin.readline # Don't forget to rstrip()

# testcases = int(input())
def solution():
    numCards,maxVal = map(int, input().split())
    cards = list(map(int, input().split()))
    summation = abs(sum(cards))
    print(int(math.ceil(float(summation) / maxVal)))



solution()