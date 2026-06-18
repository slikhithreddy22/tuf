root = [3, 5, 1, 6, 2, 0, 8, None, None, 7, 4]

p = 5
q = 1


def find_depth(node, root):
    n = root.index(node)
    return n


def lca(root, p, q):
    first = find_depth(p, root)
    second = find_depth(q, root)

    mini = min(first, second)
    first = second = mini
