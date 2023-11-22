import sys
import math
import heapq
import collections
# import numpy as np
# from numpy.fft import fft, ifft

input = sys.stdin.readline # Don't forget to rstrip()

testcases = 1
# testcases = int(input())
def solution():
    n = map(int, input())
    teams = []
    for _ in range(n):
        line = map(str, input().split())
        teams.append(line)
    
    strs = {}
    possible_team_set = {}
    for i in range(n):
        for j in range(n):
            if (teams[i][j] == '*'): 
                continue   
            for k in range(len(teams[i][j])):
                
                
        
    

for i in range(testcases):
    solution()