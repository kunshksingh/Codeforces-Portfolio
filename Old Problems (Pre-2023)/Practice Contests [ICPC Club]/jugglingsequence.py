#Make juggling WITHOUT using brute force
def juggling(n,m):
    if m == 1:
        return 1
    elif n <= 2*m-1:
        return (n+2)//2  #integer division, round up to nearest integer. So 3/2 = 2 and 4/2=3 etc...
    else:
        return juggling(n-m,m)
        
testcases = int(input())
retList = []
for k in range(testcases):
    temp = input().split()
    n = int(temp[0])
    m = int(temp[1])
    retList.append(juggling(n,m))
for k in retList:
    print(k)


