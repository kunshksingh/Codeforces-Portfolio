for _ in range (int(input())):
    strLen = int(input())
    tim = list(input())
    while ((len(tim) > 1 )and (tim[0] == "0" and tim[-1] == "1" or tim[0] == "1" and tim[-1] == "0")):
        tim.pop(0)
        tim.pop(-1)
    print(len(tim))
