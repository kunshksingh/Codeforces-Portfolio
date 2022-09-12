import math
class Solution:
    testcases = int(input())
    solutions = [] 
    def logSort():
        #Handle Input
        numElements = int(input())
        a = list(map(int, input().split())).sort()
        keysA = math.log10(int(char)) for char in a
        dictA = dict(zip(keysA, a))
        b = set(map(str, input().split())).sort()

        retNum = 0

        #i = 0
        for num in a:
            if (len(num) > 1):


      
                

        return retNum
    for i in range(testcases):
        solutions.append(logSort())
    for ans in solutions:
        print(ans)
