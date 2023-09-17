months = {"JAN": 0, "FEB": 31, "MAR": 59, "APR":90, "MAY":120, "JUN":151, "JUL":181, "AUG":212, "SEP":243, "OCT":273, "NOV": 304, "DEC":334}
temp = input().split()
day = int(temp[0])
monthOff = months[temp[1]]
offset = {"SAT":1, "SUN":2, "MON":3, "TUE":4, "WED":5, "THU":6, "FRI":0}
off = offset[input()]
dt = off + monthOff + day -1
if ((temp[1] == "JAN" or temp[1] == "FEB")):
    if (dt % 7 == 0):
        print("TGIF")
    else: 
         print(":(")
else:
    dt += 1
    if(dt % 7 == 1 or dt % 7 == 0):
        print("not sure")
    else:
        print(":(")
 