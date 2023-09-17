import code


class Solution:
    
    testcases = int(input())
    def decoder(): #char 97 = a
        codeLen = int(input())
        encoded = list((str(input())))
        decoded = ""
        i = 0
        while (i < codeLen):
            if (i+3 < codeLen and encoded[i+2] == "0" and encoded[i+3] != "0"):
                decoded += chr((int(encoded[i])*10)+int(encoded[i+1]) + 96)
                i+= 2
            elif(i+3 == codeLen and encoded[i+2] == "0"):
                decoded += chr((int(encoded[i])*10)+int(encoded[i+1]) + 96)
                i+= 2
            else:
                decoded += chr(int(encoded[i])+96)
            i += 1
        
        return decoded
    decodedList = []

    for i in range(testcases):
        decodedList.append(decoder())
    for decode in decodedList:
        print(decode)