testcases = int(input())

def BFS(edges, start, end):
    visited = [False] * len(edges)
    queue = []
    queue.append(start)
    visited[start] = True
    while queue:
        s = queue.pop(0)
        for i in edges[s]:
            if visited[i] == False:
                queue.append(i)
                visited[i] = True
    return visited[end]

def solution():
    n, m = map(int, input().split())
    edges = []
    for i in range(m):
        a, b = map(int, input().split())
        edges.append((a, b))
        

    


    return

for _ in testcases:
    solution()

