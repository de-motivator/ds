class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Construct expression tree from prefix
def construct_tree_from_prefix(prefix):
    stack = []
    for ch in reversed(prefix):
        if ch.isalnum():
            stack.append(Node(ch))
        else:
            node = Node(ch)
            node.left = stack.pop()
            node.right = stack.pop()
            stack.append(node)
    return stack[-1]

# Non-recursive postorder traversal
def postorder_non_recursive(root):
    if not root:
        return
    s1, s2 = [], []
    s1.append(root)
    while s1:
        node = s1.pop()
        s2.append(node)
        if node.left:
            s1.append(node.left)
        if node.right:
            s1.append(node.right)
    print("Postorder Traversal:", end=" ")
    while s2:
        print(s2.pop().data, end=" ")
    print()

# Delete the tree (by dereferencing)
def delete_tree(root):
    if root:
        delete_tree(root.left)
        delete_tree(root.right)
        root.left = root.right = None

# Main
prefix = "+--a*bc/def"
print("Prefix Expression:", prefix)

root = construct_tree_from_prefix(prefix)
postorder_non_recursive(root)
delete_tree(root)
print("Tree deleted successfully.")
