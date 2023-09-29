import sys
input = sys.stdin.readline

def solution():
    n_letters = int(input())
    bigrams = "".join(list(map(str, input().split())))
    missing_bigram = bigrams[0]
    for i in range(1,len(bigrams)):
        if (bigrams[i] == bigrams[i-1] and i%2 == 0 and len(bigrams)*2 - len(missing_bigram)> n_letters):
            continue
        missing_bigram += bigrams[i]
    while len(missing_bigram)<n_letters:
        missing_bigram += 'b'
    print(missing_bigram)
testcases = int(input())
for i in range (testcases):
    solution()