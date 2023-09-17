t = list(map(int, input().split()))

diff1 = t[1]-t[0]
diff2 = t[2]-t[1]
if(t[2] == t[1] and t[1] == t[0]):
    print("braked")
elif((((((((0 != diff1 and 0 != diff2 )))))))and ((1 == (diff1/abs(diff1)) and -1 == (diff2/abs(diff2))) or (-1 == (diff1/abs(diff1)) and 1 == (diff2/abs(diff2))))):
    print("turned")
elif (abs(diff2) > abs(diff1)):
    print("accelerated")
elif(abs(diff1) > abs(diff2)):
    print("braked")
else:
    print("cruised")
