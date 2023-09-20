import sys
input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
def solution():
    n, q = map(int, input().split())
    s = str(input()).rstrip()
    for _ in range(q):
        start, end = map(int, input().split())
        zool = 0
        start -= 1
        end -= 1
        if start >= 1:
            if s[:start].find(s[start]) >= 0:
                print("YES")
                zool = 1
        if end < len(s)-1 and not zool:
            if s[end+1:].find(s[end]) >= 0:
                print("YES")
                zool = 1
        if not zool:
            print("NO")
        # for i in range(n):
            

        #Kunsh is dum
        #     zool = False
        #     if j >= len(vals):
        #         break
        #     if j > 1 and abs(vals[j-1][0] - vals[j-2][0]) == 1:
        #         i+=1
        #     if i >= n:
        #         break
        #     if vals[j][1] == int(s[i]):
        #         vals[j] = (i, int(s[i]))
        #         j+=1

        # for i in range(2,len(vals)):
        #     if (abs(vals[i][0] - vals[i-1][0]) == 1 and abs(vals[i-1][0] - vals[i-2][0]) == 1) or (vals[i-1] == vals[i]):
        #         print("NO")
        #         zool = True
        #         break
                
        # if not zool:
        #     print("YES") 

        
for i in range(testcases):
    solution()