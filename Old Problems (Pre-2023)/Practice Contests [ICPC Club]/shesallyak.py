import collections
class Solution:


    def danceOrder():
        danceNums = input().split(' ')
        dances = collections.defaultdict(list)
        for i in range(int(danceNums[0])):
            temp = input().split(' ')
            dances[i].append((int(temp[0],int(temp[1]))))

        

    danceOrder()