import random
t = ''
print(2)
for i in range(2):
    print(100000, 'y')
    t = ''
    for j in range(100000):
        rand = random.randint(1,3)
        if rand == 1:
            t += 'r'
        if rand == 2:
            t += 'g'
        if rand == 3:
            t += 'y'
    print(t)
