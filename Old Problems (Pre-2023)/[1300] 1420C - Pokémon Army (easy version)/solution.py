

testcases = int(input())
retList = []

for k in range(testcases):
    temp = input().split(' ')
    pokemonNum = int(temp[0])
    swaps = int(temp[1]) #Don't need to use this for easy version

    pokemonPowers = []
    powers = input().split(' ')
    for pow in powers:
        pokemonPowers.append(int(pow))
    
    pokemonPowersOffset = pokemonPowers.copy()[1:]

    for i in range(0,len(pokemonPowers)-1):
        if (i % 2 == 0):
            pokemonPowers[i] += pokemonPowers[i+1]
            pokemonPowersOffset[i] += pokemonPowers[i+1]
        else:
            pokemonPowers[i] -= pokemonPowers[i+1]
            pokemonPowersOffset[i] -= pokemonPowers[i+1]
    print(pokemonPowers)
    print(pokemonPowersOffset)
    if (len(pokemonPowers)-1 % 2 == 0):
        pokemonPowers[i] += pokemonPowers[i+1]
        pokemonPowersOffset[i] += pokemonPowers[i+1]

    maxPow = max(pokemonPowers)
    maxPow2 = max(pokemonPowersOffset)
    retList.append(max(maxPow,maxPow2))

for output in retList:
    print(output)