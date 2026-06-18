graph = {
    0: {1, 2, 3},
    1: {0, 4, 5},
    2: {0, 6, 7},
    3: {0},
    4: {1, 8},
    5: {1},
    6: {2},
    7: {2, 9},
    8: {4, 10},
    9: {7, 11},
    10: {8, 12},
    11: {9, 13},
    12: {10, 14},
    13: {11, 15},
    14: {12},
    15: {13},
}


def tree_centre(graph):
    n = len(graph)
    degrees = [0] * n
    leaves = []
    for node in graph:
        degrees[node] = len(graph[node])
        if degrees[node] == 1 or degrees[node] == 0:
            leaves.append(node)
    count = len(leaves)
    while count < n:
        new_leaves = []
        for leaf in leaves:
            for neigh in graph[leaf]:
                degrees[neigh] -= 1
                if degrees[neigh] == 1:
                    new_leaves.append(neigh)
        leaves = new_leaves
        count += len(new_leaves)
    return leaves


print(tree_centre(graph))
