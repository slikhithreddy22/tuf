class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def inorder(root):
    if root:
        inorder(root.left)
        print(str(root.data)+"->",end=" ")
        inorder(root.right)
def preorder(root):
    if root:
        print(str(root.data)+"->",end="")
        preorder(root.left)
        preorder(root.right)
def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(str(root.data)+"->",end="")

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

print("Inorder traversal ")
inorder(root)
print()
print("Preorder traversal ")
preorder(root)
print()
print("Postorder traversal ")
postorder(root)
print()
