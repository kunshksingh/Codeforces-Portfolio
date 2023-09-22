import sys
import math
import heapq
import collections
# import numpy as np
# from numpy.fft import fft, ifft

input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
def solution():
    n = int(input())
    birthday = list(map(int, input().split()))
    birthday[birthday.index(min(birthday))] += 1
    birthday_mult = 1
    for i in birthday:
        birthday_mult *= i
    print(birthday_mult)


for i in range(testcases):
    solution()