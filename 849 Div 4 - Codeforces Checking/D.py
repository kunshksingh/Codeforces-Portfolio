from collections import *

for _ in range(int(input())):
    strL = int(input())
    splitter = input()
    dp = [0 for i in range(strL)] 
    l = 0
    r = 0
    lDict =  defaultdict(int)
    rDict =  defaultdict(int)

    r += len(set(splitter))
    for i in range(strL-1, -1 ,-1):
        rDict[splitter[i]] += 1

    for i in range(strL):
        if splitter[i] not in lDict.keys():
            lDict[splitter[i]] += 1
        rDict[splitter[i]] -= 1
        if rDict[splitter[i]] == 0:
            del rDict[splitter[i]] 
        l = len(lDict.keys())
        r = len(rDict.keys())
        dp[i] = l + r
    print(max(dp))
        

