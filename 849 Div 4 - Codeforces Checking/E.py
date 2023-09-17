for _ in range(int(input())):
    elms = int(input())
    arr = list(map(int,input().split()))
    sumA = sum(arr)
    dp = []
    arr.sort()
    for i in range(1, len(arr)):
        if (abs(arr[i-1]) >= abs(arr[i]) and arr[i-1] < 0):
            arr[i-1] = -1*arr[i-1]
            arr[i] = -1*arr[i]

    print(sum(arr))