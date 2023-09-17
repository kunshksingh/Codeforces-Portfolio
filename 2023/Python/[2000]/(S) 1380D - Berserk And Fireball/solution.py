

def solution():    
    inputLens = list(map(int, input().split()))

    costs = list(map(int, input().split()))
    fireball = costs[0]
    fireballRange = costs[1]
    beserk = costs[2]

    soldiers = list(map(int, input().split()))
    endSoldiers = list(map(int, input().split()))

    if soldiers == endSoldiers:
        return 0
    if len(soldiers) == len(endSoldiers):
        return -1
    # cost = [0 for i in range(len(soldiers))]
    cost = 0
    j = 0
    isFireballEffective = beserk * fireballRange > fireball
    subrange = []
    soldiersAdded = []
    for i in range(len(soldiers)):
        if j >= len(endSoldiers) or soldiers[i] != endSoldiers[j]:
            subrange.append(soldiers[i])
        else:
            soldiersAdded.append(soldiers[i])
            if len(subrange) > 0:
                if isFireballEffective and fireballRange <= len(subrange):
                    cost += fireball * (len(subrange) // fireballRange) + beserk * (len(subrange) % fireballRange)
                else:
                    if max(subrange) > soldiers[i] and (i-len(subrange)-1 >= 0 and max(subrange) > soldiers[i-len(subrange)-1] or i-len(subrange)-1 < 0):
                        if fireballRange > len(subrange):
                            return -1
                        cost += fireball + beserk * (len(subrange)-fireballRange)
                    else:
                        cost += beserk * len(subrange)
            j += 1
            subrange = []
    if len(subrange) > 0:
        if isFireballEffective and fireballRange <= len(subrange):
            cost += fireball * (len(subrange) // fireballRange) + beserk * (len(subrange) % fireballRange)
        else:
            if i-len(subrange) >= 0 and max(subrange) > soldiers[i-len(subrange)]:
                if fireballRange > len(subrange):
                    return -1
                cost += fireball + beserk * (len(subrange)-fireballRange)
            else:
                cost += beserk * len(subrange)
    if soldiersAdded != endSoldiers:
        return -1
    return cost

    

print(solution())