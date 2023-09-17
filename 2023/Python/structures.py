'''
Factorials from 0 to BOUND
'''
num = 1
factorial = {}
factorial[0] = 1

BOUND = 10**6
M = ((10**9)+7)

for i in range(1,BOUND+1):
    num = (num * i) % M
    factorial[i] = num
    factorial[-i] = 1/num
'''
get_degree(n, p) with which p is in n!
'''
def get_degree(n, p):
    degree = 0
    u = p
    temp = n
    while u <= temp:
        degree += temp // u
        u *= p
    return degree
'''
FAST_EXP (Set Modulo = 1 to disable)
'''
def fast_pow(base, exp, modulo):
    res = 1
    cur = base
    while exp > 0:
        if exp % 2 == 1:
            res = (res * cur) % modulo
        cur = (cur * cur) % modulo
        exp //= 2
    return res

'''
MAX-HEAP 
'''
import heapq

# Create a list to store the elements of the heap
heap = []
heapq.heapify(heap)

# Add elements to the heap
heapq.heappush(heap, 1)
heapq.heappush(heap, 2)
heapq.heappush(heap, 3)

# Remove the maximum element from the heap
max_element = heapq.heappop(heap)

'''
DSUs
'''
class DSU:
    def __init__(self, n):
        self.parent = [i for i in range(n)]  # Initially, every element is its own parent.
        self.size = [1] * n  # Size of the set (used for union by size).

    def find(self, x):
        # Path compression
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)

        if rootX != rootY:
            # Union by size.
            if self.size[rootX] < self.size[rootY]:
                rootX, rootY = rootY, rootX  # Swap to ensure rootX is the root of the larger set.

            self.parent[rootY] = rootX
            self.size[rootX] += self.size[rootY]

'''
PASCALS
'''
pascalNum = 0
pascalNums = {1:0}
for i in range (1, 100000):
    pascalNum += i
    pascalNums[i+1] = pascalNum

'''
IS PRIME
'''
import math

def is_prime(n):
  if n <= 1:
    return False
  for i in range(2, int(math.sqrt(n)) + 1):
    if n % i == 0:
      return False
  return True
