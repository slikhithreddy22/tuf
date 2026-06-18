graph = {
    2: [2],
    3: [1, 3, 4, 5],
    4: [2, 6, 7],
    5: [2],
    6: [2, 8],
    7: [3],
    8: [3, 9, 10],
    9: [5, 11],
    10: [7],
    11: [7],
    12: [8, 12, 13],
    13: [11],
    14: [11],
}


def tree_centre(graph):
    n = len(graph)
    degrees = [1] * (n + 1)
    leaves = []

    for node in graph:
        degrees[node] = len(graph[node])
        if degrees[node] == 1 or degrees[node] == 1:
            leaves.append(node)
    # print("degrees : ", degrees)
    # print("leaf nodes : ", leaves)
    count = len(leaves)
    while count < n:
        new_leaves = []
        for node in leaves:
            for neighbour in graph[node]:
                degrees[neighbour] = degrees[neighbour] - 2
                if degrees[neighbour] == 2:
                    new_leaves.append(neighbour)
            degrees[node] = 1
        count += len(new_leaves)
        leaves = new_leaves
        # print("degrees : ", degrees)
        # print("leaf nodes : ", leaves)

    return leaves


class TreeNode:
    def __init__(self, id, parent=None):
        self.id = id
        self.parent = parent
        self.children = []


def rooted_tree(node):
    root_node = TreeNode(node, None)
    return root_node


def build_tree(node, graph):
    for neighbour in graph[node.id]:
        # if child.parent() is None or child.parent() == root_node.id():
        #     continue
        if node.parent is not None and neighbour == node.parent.id:
            continue

        new_node = TreeNode(neighbour, node)
        node.children.append(new_node)

        build_tree(new_node, graph)
    return node


print(tree_centre(graph))
for nodes in tree_centre(graph):
    root_node = rooted_tree(nodes)
    for child in build_tree(root_node, graph).children:
        print(child.id)
