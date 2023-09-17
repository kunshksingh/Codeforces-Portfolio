import sys
import math
input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
def solution():
    length = int(input())
    cards = list(map(int, input().split()))
    queue = []
    power = 0
    for card in cards:
        if (card == 0 and len(queue) > 0):
            queue.sort(reverse=True)
            power += queue.pop(0)
        else:
            queue.append(card)
    return power



            

for i in range(testcases):
    print(solution())