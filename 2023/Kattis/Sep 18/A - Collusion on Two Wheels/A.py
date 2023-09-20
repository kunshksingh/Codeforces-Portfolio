import sys
import math
import heapq
import collections
# import numpy as np
# from numpy.fft import fft, ifft

input = sys.stdin.readline # Don't forget to rstrip()

import math
 
 
# class Point:
#     def __init__(self, tuplet):
#         self.x = tuplet[0]
#         self.y = tuplet[1]
 
 
# def compareX(a, b):
#     p1 = a
#     p2 = b
#     return (p1.x - p2.x)
 
 
# def compareY(a, b):
#     p1 = a
#     p2 = b
#     return (p1.y - p2.y)
 
 
# def dist(p1, p2):
#     return math.sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y))
 
 
# def bruteForce(P, n):
#     min_dist = float("inf")
#     for i in range(n):
#         for j in range(i+1, n):
#             if dist(P[i], P[j]) < min_dist:
#                 min_dist = dist(P[i], P[j])
#     return min_dist
 
 
# def min(x, y):
#     return x if x < y else y
 
 
# def stripClosest(strip, size, d):
#     min_dist = d
#     strip = sorted(strip, key=lambda point: point.y)
 
#     for i in range(size):
#         for j in range(i+1, size):
#             if (strip[j].y - strip[i].y) >= min_dist:
#                 break
#             if dist(strip[i], strip[j]) < min_dist:
#                 min_dist = dist(strip[i], strip[j])
#     return min_dist
 
 
# def closestUtil(P, n):
#     if n <= 3:
#         return bruteForce(P, n)
#     mid = n//2
#     midPoint = P[mid]
#     dl = closestUtil(P, mid)
#     dr = closestUtil(P[mid:], n - mid)
#     d = min(dl, dr)
#     strip = []
#     for i in range(n):
#         if abs(P[i].x - midPoint.x) < d:
#             strip.append(P[i])
#     return min(d, stripClosest(strip, len(strip), d))
 
 
# def closest(points, point, mags):
#     #Only get first value once to avoid repeatedly running if statement
#     for i in range(len(points)):
#         if points[i] != point:
#             points[i][2] = math.sqrt((float(point[0])-points[i][0])**2 + (float(point[1])-points[i][0])**2)
#             mags[i] = points[i][2]
#     points = sorted(points, key=lambda x: x[2],reverse=True)

#     dists = set()

#     for i in range(len(mags)-1):
#         dists.add(math.sqrt((points[i][0] - points[i+1][0])**2 + (points[i][1] - points[i+1][1])**2))
                
    # return min(dists)

def solution():
    mags = []

    points = []
    points2 = []
    n = int(input())

    shortestDist = []
    for i in range(n):
        point = tuple(map(int, input().split()))
        dist = abs(point[0] - 5000) + abs(point[1] - 5000) #Check distance from (5000,5000)
        dist2 = int(point[0]) + 5000 + int(point[1]) + 5000  #Check distance from (-5000, -5000)
        points.append([point[0],point[1],dist]) 
        points2.append([point[0],point[1],dist2]) 


    points = sorted(points, key=lambda x: x[2],reverse=True)
    points2 = sorted(points2, key=lambda x: x[2],reverse=True)
    if n == 1:
        print(0)
    
    dists = [set() for i in range(n)]

 
    print(points)

    for i in range(0,len(points)):
        for j in range(i+1,len(points)-1):
            if (i == j+1):
                continue
            dists[i].add(abs(points[i][0] - points[j][0])+ abs(points[i][1] - points[j][1]))
            
        # dists2.add(math.sqrt((points2[i][0] - points2[i+1][0])**2 + (points2[i][1] - points2[i+1][1])**2))

        if len(dists[i]) > 0: 
            dists[i] = min(dists[i])
        else:
            dists[i] = 0
    
    dists2 = [set() for i in range(n-1)]
    for i in range(dists.index(max(dists)),len(points)):
        dists2[i].add(abs(points[i][0] - points[i+1][0])+ abs(points[i][1] - points[i+1][1]))
    return int(max(dists2))
    
    



print(solution())