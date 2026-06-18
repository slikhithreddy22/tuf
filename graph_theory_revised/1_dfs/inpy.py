def dfs(n, graph):
    visited[n] = True
    print(n)
    for i in graph[n]:
        if visited[i]:
            continue
        dfs(i, graph)


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

dfs(0, graph)
