import sys
import math
import heapq
import collections
import re
# import time
input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
def solution():
    length, color = input().split()
    color.strip()
    length = int(length)
    lightPattern = input()
    # print(length, len(lightPattern))
    if color == 'g':
        return 0
    # lightPattern = re.sub(r"[\n]*", "", lightPattern)
    # lightPattern = lightPattern.replace('\n','')
    lightPattern = lightPattern.rstrip()
    if lightPattern[length-1] == 'y' or lightPattern[length-1] == 'r':
        for i in range(length):
            if (lightPattern[i] == 'g'):
                lightPattern += 'g'
                break
            else:
                lightPattern += lightPattern[i]

    for j in range(length):
        if(lightPattern[j] == color):
            break
    lightPattern = lightPattern[j:]

    if color == 'y':
        lightPattern = re.sub(r'gg*r*', 'g', lightPattern)
     
    elif color == 'r':
        lightPattern = re.sub(r'gg*y*', 'g', lightPattern)
        # seqs = re.findall(r'[r,y]+', lightPattern)
    seqs = re.findall(r'[r,y]+', lightPattern)
    # seqs = re.findall(r'[^gg*r*|gg*y*][r,y]+', lightPattern)

    if (not seqs):
        return 0 
    maxSeq = max([len(x) for x in seqs])
    return maxSeq


    # maxSeq = 0
    # seq = 0
    # inSeq = 0


    # if (color == 'g'):
    #     return 0

    
    # for i in range(len(lightPattern)):
    #     if lightPattern[i] == 'g' and inSeq:
    #         inSeq = 0
    #         maxSeq = max(seq, maxSeq)
    #     if lightPattern[i] == color and not inSeq:
    #         inSeq = 1
    #         seq = 0
    #     seq += 1
    
    # if lightPattern[i] == 'g' and inSeq:
    #     inSeq = 0
    #     maxSeq = max(seq, maxSeq)

      
    # return maxSeq
     

# start = time.time()
for i in range(testcases):
    print(solution())
# print (time.time()-start)