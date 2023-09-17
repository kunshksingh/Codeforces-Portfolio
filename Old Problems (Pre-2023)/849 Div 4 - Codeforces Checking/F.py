def digSum(num, n):
    for x in range(n):
        num = sum([int(i) for i in str(num)])
    return num
for _ in range(int(input())):
    lens = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    dp = [0 for i in range (lens[0])]

    for i in range(lens[1]):
        newLine = list(map(int, input().split()))
        if newLine[0] == 1:
            for j in range(newLine[1]-1,newLine[2]):
                dp[j] += 1
        else:

            print(digSum(arr[newLine[1]-1],dp[newLine[1]-1]))
