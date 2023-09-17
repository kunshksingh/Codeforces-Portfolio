import sys
import math
import heapq
import collections
input = sys.stdin.readline # Don't forget to rstrip()

def solution():
    calsConv={ 0:9.0, 1:4.0, 2:4.0, 3:4.0, 4:7.0 }
    while True:
        isLast = True
        lines = []
        line = input().rstrip()
    
        while line != '-':
            line = list(map(str, line.split()))
            lines.append(line)
            line = input().rstrip()
            isLast = False

        if isLast:
            return
    

        tCals = []
        for j in lines:
            tP = 0.0
            totalCals = 0.0
            cals = []
            for i in range(len(j)):
                if j[i][-1] == "g":
                    cals.append(calsConv[i]*float(j[i][0:len(j[i])-1]))
                elif j[i][-1] == "%":
                    cals.append(0.0)
                    tP += float(j[i][0:len(j[i])-1])
                    
                else:
                    cals.append(float(j[i][0:len(j[i])-1]))

            if tP != 0:
                totalCals = sum(cals)/((1-tP/100))
            else:
                totalCals = sum(cals)
            if totalCals > sum(cals):
                for i in range(len(j)):
                    if cals[i] == 0 and j[i][-1] == "%" and float(j[i][0:len(j[i])-1]) != 0:
                        cals[i] = (float(j[i][0:len(j[i])-1])/100.0) * totalCals
            tCals.append((float(cals[0]),totalCals))

        n = 0
        k = 0
        for i in tCals:
            n += i[0]
            k += i[1]
        print(str(round((n/k)*100))+"%")



solution()