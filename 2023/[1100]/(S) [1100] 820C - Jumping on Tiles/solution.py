import sys
input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
def solution():
    word = input().rstrip()
    lastLetter = word[-1]
    wordList = list(zip([i for i in range(len(word))], [str(j) for j in word]))
    # print(wordList)
    if ord(word[0]) - ord(word[-1]) >= 0:
        wordList2 = list(sorted(wordList, key = lambda x:((ord(x[1])-ord(wordList[0][1]))!=0,(ord(x[1])-ord(wordList[0][1]))>0, 1/ord(x[1])-ord(wordList[0][1]))))
        # for x in wordList2:
        #     print(ord(x[1])-ord(wordList[0][1]), x[1])
    else:
        wordList2 = list(sorted(wordList, key = lambda x:((ord(x[1])-ord(wordList[0][1]))!=0,(ord(x[1])-ord(wordList[0][1]))<0, ord(x[1])-ord(wordList[0][1]))))


    path = []
    bjool = 1
    i = 0
    while(i < len(wordList2)):
        if (wordList2[i][1] == lastLetter):
            bjool = 0
        elif (bjool == 0):
            break
        path.append(wordList2[i])
        i += 1

    path2 = []
    bjool = 1
    i = 0


    if len(path) < len(path2) and sum([p1[0] for p1 in path])>=sum([p2[0] for p2 in path2]):
        path = path2

    print(str(abs(ord(word[0])-ord(word[-1]))) + " " + str(len(path)))
    print(' '.join([str(pathVal[0]+1) for pathVal in path]))

    # letterSet = set(word)
    # wordList = zip([i for i in letterSet], [j for j in letterSet])
    # for i in wordList:
    #     if i[0] == i[1]:
    #         wordList.remove(i)
    # wordList = zip( , sorted(wordList, key=lambda x:abs(int(x[0])-int(x[1]))))
    # visited = []
    # summation = 0
    # for i in range(wordList):
    #     if wordList[i] == word[-1]:
    #         summation += wordList[i]
    #         visited.append(wordList[i])
    #         break
    #     visited.append(wordList[i])
    # print(sum())


for i in range(testcases):
    solution()