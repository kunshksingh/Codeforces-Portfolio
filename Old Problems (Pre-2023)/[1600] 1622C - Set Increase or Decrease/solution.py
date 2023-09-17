import collections

def minsum(arr, minimum, maximum):
    counter = 0
    for i in range(len(arr)-1,-1,-1):
        if (sum(arr) <= maximum):
            return counter
        arr[i] = minimum
        counter += 1
    return len(arr)

def findMin(arr, upperSum):
    counter = 0
    dp = [0 for i in range(len(arr))] 
    for i in range(len(arr)):
        dp[i] = (arr[i]*len(arr))-(upperSum*(i+1))

    adjust = min(dp)
    arr[0] -= adjust
    counter += adjust
    print("Counter",counter)
    counter += minsum(arr,arr[0],upperSum)
    print("counter",counter)
    
    return counter

def main():
    arraySize,upperSum = map(int,input().split())
    arr = list(map(int,input().split()))
    arr.sort(reverse=False)
    return findMin(arr, upperSum)


testcases = int(input())

outputs = []

for i in range(testcases):
    outputs.append(main())
for output in outputs:
    print(output)
        

