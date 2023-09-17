import sys
import math
input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
# def countFours(t,n):
#     numFours = 0
#     digit_g = t // (10**n)
#     if t < 4:
#         return 0 
#     if t < 14:
#         return 1
#     if t < 40:
#         return 2
#     if digit_g < 4:
#         for i in range(n,0,-1):
#             numFours += ((-1)**(i%2 != n%2) * (10)**(i-1) * (n + -n*(n <= 1)))
#     elif digit_g > 4:
#         for i in range(n+1,0,-1):
#             numFours += ((-1)**(i%2 != n%2) * (10)**(i-1) * (n + -n*(n <= 1)))
#     else:
#         for i in range(n,0,-1):
#             numFours += ((-1)**(i%2 != n%2) * (10)**(i-1) * (n + -n*(n <= 1)))
#         numFours += 10**n % n

#     return numFours
def solution():
    # #Count fours
    # n = int(math.log(t,10))
    # currFours = countFours(t,n)
    # numFours = currFours
    # while(currFours >= 4):
    #     currFours = countFours(t,n)
    #     numFours += currFours

    # #Compute fours for n-1

    # return t + numFours
    t = int(input())
    str_t = []
    while t > 0:
        str_t.append(t%9)
        t //= 9
    for i in range(len(str_t)):
        if (str_t[i] >= 4):
            str_t[i] += 1
        str_t[i] = str(str_t[i])
    str_t = list(reversed(str_t))
    num_t = int(''.join(str_t))
    return num_t


for i in range(testcases):
    print(solution())