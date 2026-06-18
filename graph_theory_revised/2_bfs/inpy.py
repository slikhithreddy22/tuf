def bfs(start, graph):
    queue = [start]
    print(queue[0])
    visited[queue[0]] = True
    while queue:
        top = queue[0]
        queue.pop(0)
        for neigh in graph[top]:
            if visited[neigh]:
                continue
            print(neigh)
            visited[neigh] = True
            queue.append(neigh)


graph = {
    0: {1, 2},
    1: {0, 3, 4},
    2: {0, 5, 6},
    3: {1},
    4: {1},
    5: {2},
    6: {2},
}
n = len(graph)
visited = [False] * n

bfs(0, graph)
