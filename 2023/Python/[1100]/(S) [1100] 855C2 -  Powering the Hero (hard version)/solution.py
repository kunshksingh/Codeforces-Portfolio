import sys
import math
import heapq
input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
def solution():
    length = int(input())
    cards = list(map(int, input().split()))
    queue = []
    heapq.heapify(queue)
    power = 0
    for card in cards:
        if (card == 0):
            if(len(queue) > 0):
                power += (heapq.heappop(queue) * -1)
        else:
            heapq.heappush(queue,(card*-1))
    return power            

for i in range(testcases):
    print(solution())