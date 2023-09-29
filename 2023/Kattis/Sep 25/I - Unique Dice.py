import sys
import math
import heapq
import collections
# import numpy as np
# from numpy.fft import fft, ifft

input = sys.stdin.readline # Don't forget to rstrip()

testcases = 1
# testcases = int(input())
def solution():
    n = int(input())
    same_dice = {}
    for i in range(n):
        dice = list(map(str, input().split()))
        # dice.append(dice[0])
        print(dice)
        dice_pairs = []
        dice_pairs.append("".join(sorted(dice[0]+dice[2]+dice[3]+dice[4]+dice[5])))
        dice_pairs.append("".join(sorted(dice[1]+dice[2]+dice[3]+dice[4]+dice[5])))
  

        tuplets = []
        for pair in dice_pairs:
            tuplets.append(pair)
        tuplets.sort()

        if ((tuplets[0], tuplets[1]) not in same_dice.keys()):
            same_dice[(tuplets[0], tuplets[1])] = 1
        else:
            same_dice[(tuplets[0], tuplets[1])] += 1
    print(same_dice)
    print(max(same_dice.values()))

            
            
    
    '''
    int n, val;
    int maximum;
    cin >> n;
    map<string, int> dice_seq;
    for (int i = 0; i < n; i++){
        vector<int> dice;
        for (int j = 0; j < 6; j++){
            cin >> val;
            dice.push_back(val);
        }
        dice.push_back(dice[0]);
        dice.push_back(dice[1]);
        dice.push_back(dice[2]);
        dice.push_back(dice[3]);
        dice.push_back(dice[4]);
        set<string> dice_seq_tried;
        for (int j = 0; j < 5; j++){
            if (dice_seq_tried.find((to_string(dice[j])+to_string(dice[j+2])+to_string(dice[j+3])+to_string(dice[j+4])+to_string(dice[j+5]))) != dice_seq_tried.end()){
                continue;
            }
            dice_seq[(to_string(dice[j])+to_string(dice[j+2])+to_string(dice[j+3])+to_string(dice[j+4])+to_string(dice[j+5]))] += 1;
            dice_seq_tried.insert((to_string(dice[j])+to_string(dice[j+2])+to_string(dice[j+3])+to_string(dice[j+4])+to_string(dice[j+5])));
        }

    }
    '''

for i in range(testcases):
    solution()