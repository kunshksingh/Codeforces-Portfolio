import collections
import itertools

class Solution:
    string = str(input())
    meowDict = collections.defaultdict(int)
    meowSet = set(["m","e","o","w"])
    meowPerms = itertools.permutations(meowSet)

    nextMeow = {
        "m":"e",
        "e":"o",
        "o":"w",
        "w":""
    }
    stringSet = set(string)
    hasAnyMeow = False
    for i in string:
        if i in meowSet:
            hasAnyMeow = True
            break
    
    if (not hasAnyMeow):
        print(4)
        quit()

    if ("meow" in string):
        print(0) 
        quit()
    purr = "meow"
    diff = 0
    for perm in meowPerms:
        if str(''.join(map(str,perm))) in string:
            #print("TRUE TRUE")
            solvedStr = ''.join(map(str,perm))
            for g in range(len(solvedStr)):
                if solvedStr[g] != purr[g]:
                    diff += 1
            if (diff <= 2):
                print(1)
            else:
                print(2)
            quit()

    counter = 4
    minCounter = 5
    #3 cases
        #1. Must replace 1-4 to get to "meow" (insert/replace) < Accounted for by logic below line 49
        #2. Delete 1 char to get closer to meow (delete) < Accounted for by final meow (line 75)
        #3. Swap 2 chars to get closest to meow (swap) < Accounted for by line 29

    #Check longest continguous meow substring
    lastFound = set()
    longestContiguous = 1
    for i in range(len(string)):
        if (string[i] in meowSet):
            meowDict[i] = string[i]

    prevI = -999
    nextMeowStr = ""
    count = 0
    finalMeow = False
    finalMeowSet = set() #Check for case when "mexow"

    for j in meowDict:
        if (prevI == -999): #initial case
            prevI = j
            nextMeowStr = meowDict[j]
            nextMeowStr = nextMeow[nextMeowStr]
            count += 1
            continue
        if (prevI+1 == j):
            nextMeowStr = nextMeow[nextMeowStr]
            prevI = j
            count += 1
        else:
            if count == 2 and nextMeowStr == "o": #For final meow
                finalMeowSet.add(prevI)
            elif count == 2 and nextMeowStr == "" and j - 3 in finalMeowSet:
                finalMeow = True
                break
            if count > longestContiguous:
                longestContiguous = count
            prevI = j
            nextMeowStr = nextMeow[meowDict[j]]
            count = 1
    #print(count)
    #print(finalMeowSet)
    if count == 2 and nextMeowStr == "" and j - 3 in finalMeowSet:
        finalMeow = True

    if count > longestContiguous:
        longestContiguous = count

    if (finalMeow):
        print(1)
        quit()

    print((4-longestContiguous))
