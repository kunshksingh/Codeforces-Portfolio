def checkAcyclic(forest, newNode):
    return False
def solution():    
    n, m_1, m_2 = map(int, input().split())
    mochaForest = list(map(tuple, input()))   
    dianaForest = list(map(tuple, input()))


    acylicNodes = []
    for i in range(1, n):
        for j in range(1 ,n):
            if checkAcyclic(mochaForest, (i, j)) and checkAcyclic(dianaForest, (i,j)):
                acylicNodes.append((i, j))



    print(len(acylicNodes))
    for i in acylicNodes:
        print(i[0], i[1])

    





solution()