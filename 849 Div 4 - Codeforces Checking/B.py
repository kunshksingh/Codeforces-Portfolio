for _ in range(int(input())):
    vool = False
    strLen = int(input())
    command = input()
    x = 0
    y = 0
    for i in range(strLen):
        if (x,y) == (1,1) and not vool:
            print("YES")
            vool = True
        if (command[i] == "U"):
            y+= 1
        elif (command[i] == "D"):
            y-=1
        elif (command[i] == "R"):
            x+=1
        elif (command[i] == "L"):
            x-=1
    if (x,y) == (1,1) and not vool:
        print("YES")
        vool = True
    if (not vool):
        print("NO")