class DSU:
    def __init__(self, n):
        self.parent = [i for i in range(n)]  
        self.size = [1] * n  

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)

        if rootX != rootY:
            if self.size[rootX] < self.size[rootY]:
                rootX, rootY = rootY, rootX  

            self.parent[rootY] = rootX
            self.size[rootX] += self.size[rootY]


import sys
import math
import heapq
import collections
input = sys.stdin.readline # Don't forget to rstrip()

testcases = int(input())
def solution():
    n,m,k = map(int, input().split())
    grid = []
    for i in range(n):
        grid.append(DSU(map(int, input()))) 


solution()