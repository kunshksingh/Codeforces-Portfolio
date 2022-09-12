from asyncio import set_child_watcher
import collections


class Solution:
    #COULD HAVE JUST REVERSE SORTED AND THEN APPENDED STARTING FROM WHERE THE FIRST INDEX IS
    testcases = int(input())
    def jumping():
        path = [-2]
        cost = 0
        tiles = list(str(input()))
        dsu = collections.defaultdict(list)
        for i in range(0, len(tiles)):  
            dsu[tiles[i]].append(i+1)
        distribution = [0,0]
        for tile in tiles:
            if (ord(tile)-96 < ord(tiles[0])-96):
                distribution[0] += 1
            else:
                distribution[1] += 1
        if (max(distribution[0],distribution[1]) == distribution[0]):
            tiles.sort(reverse=True)
        else:
            tiles.sort(reverse=False)
        prev = -1
        started = False
        #print(tiles)
        for i in tiles:
            #print(i, chr(prev+96), started, path)
            if i == chr(prev+96):
                continue
            if (1 in dsu[i]):
                started = True
            if (not started):
                continue
            if prev == -1:
                path.extend(dsu[i])
                prev = int(ord(i)-96)
                continue
            if (dsu[i] == len(tiles)):
                path.extend(dsu[i])
                cost += ord(i)-96-prev
                prev = int(ord(i)-96)
                break
            path.extend(dsu[i])
            cost += ord(i)-96-prev
            prev = int(ord(i)-96)
        path.pop(0)
        return (cost,path)

    jumpedTiles = []
    for i in range(testcases):
        jumpedTiles.append(jumping())

    
    for tilez in jumpedTiles:
        print(abs(tilez[0]), len(tilez[1]))
        print(' '.join(str(tile) for tile in tilez[1]))
        