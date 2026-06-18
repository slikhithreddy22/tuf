graph = {
    1: [2],
    2: [1, 3],
    3: [2, 4, 9],
    4: [3, 5],
    5: [4, 6, 13],
    6: [5, 7, 16],
    7: [6, 8],
    8: [7, 20, 22],
    9: [3, 10],
    10: [9, 11],
    11: [10, 12],
    12: [11],
    13: [5, 14],
    14: [13, 15],
    15: [14],
    16: [6, 17],
    17: [16, 18],
    18: [17, 19],
    19: [18],
    20: [8, 21],
    21: [20],
    22: [8, 23],
    23: [22, 24],
    24: [23, 25],
    25: [24],
}


def tree_centre(graph):
    n = len(graph)
    degrees = [0] * (n + 1)
    leaves = []

    for node in graph:
        degrees[node] = len(graph[node])
        if degrees[node] == 0 or degrees[node] == 1:
            leaves.append(node)
    print("degrees : ", degrees)
    print("leaf nodes : ", leaves)
    count = len(leaves)
    while count < n:
        new_leaves = []
        for node in leaves:
            for neighbour in graph[node]:
                degrees[neighbour] = degrees[neighbour] - 1
                if degrees[neighbour] == 1:
                    new_leaves.append(neighbour)
            degrees[node] = 0
        count += len(new_leaves)
        leaves = new_leaves
        print("degrees : ", degrees)
        print("leaf nodes : ", leaves)

    # for i in range(len(degrees)):
    #     if degrees[i] != 0:
    #         print(i)
    #
    print(degrees)
    return leaves


tree_centre(graph)
