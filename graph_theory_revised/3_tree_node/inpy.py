class TreeNode:
    def __init__(self, n, parent):
        self.node = n
        self.parent = parent
        self.children = []

    def get_children(self):
        return self.children

    def get_parent(self):
        return self.parent

    def add_children(self, node):
        self.children.append(node)


def rootTree(node):
    root = TreeNode(node, None)
    return root


def buildTree(graph, node):
    for neighbour in graph[node]:
        if neighbour.parent and neighbour.parent.node == node:
            continue
        child = TreeNode(neighbour, node)
        node.add_children(child)
        buildTree(graph, child)
    return node
