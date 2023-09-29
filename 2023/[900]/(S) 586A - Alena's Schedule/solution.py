import sys
import math
import re
input = sys.stdin.readline # Don't forget to rstrip()

def solution():
    n = int(input())
    schedule = list(map(int, input().split()))
    if sum(schedule) == 0:
        return 0
    schedule_str = "".join(map(str,schedule)).lstrip("0").rstrip("0")
    scheduleNotUni = re.findall("000*", schedule_str) 
    hoursNotAtUni = 0
    for i in range(len(scheduleNotUni)):
        hoursNotAtUni += len(scheduleNotUni[i])
    return len(schedule_str) - hoursNotAtUni



print(solution())