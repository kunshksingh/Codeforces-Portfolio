class Solution:
    testcases = int(input())
    printAllCases = []
    def cardShuffle():
       
        #Take in cards inputs
        numCards = int(input())
        cards = list(map(int,input().split()))
        numShuffles = int(input())
        shuffles = list(map(int,input().split()))

        #Calculate each shuffle position
        deckPos = 0
        for shuffle in shuffles:
            deckPos += shuffle
            if deckPos >= len(cards):
                deckPos -= len(cards)
        return cards[deckPos]



    for i in range(0, testcases):
        printAllCases.append(cardShuffle())
    for case in printAllCases:
        print(case)