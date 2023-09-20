import sys
input = sys.stdin.readline # Don't forget to rstrip()

# testcases = int(input())
#8, 4, 2, 6, 8
def solution():
    num = int(input())
    if num == 0:
        print(1)
    else:
        print((num%4 == 1) * 8 + (num%4 == 2) * 4 + (num%4 == 3) * 2 +  (num%4 == 0) * 6)


solution()