class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Insert node
def insert(root, data):
    if root is None:
        return Node(data)
    if data < root.data:
        root.left = insert(root.left, data)
    elif data > root.data:
        root.right = insert(root.right, data)
    return root

# Search node
def search(root, key):
    if root is None:
        return False
    if root.data == key:
        return True
    if key < root.data:
        return search(root.left, key)
    return search(root.right, key)

# Find minimum value node
def find_min(node):
    current = node
    while current.left is not None:
        current = current.left
    return current

# Delete node
def delete_node(root, key):
    if root is None:
        return root
    if key < root.data:
        root.left = delete_node(root.left, key)
    elif key > root.data:
        root.right = delete_node(root.right, key)
    else:
        if root.left is None:
            return root.right
        elif root.right is None:
            return root.left
        temp = find_min(root.right)
        root.data = temp.data
        root.right = delete_node(root.right, temp.data)
    return root

# Inorder traversal
def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end=" ")
        inorder(root.right)

# Main program
root = None
root = insert(root, 50)
insert(root, 30)
insert(root, 70)
insert(root, 20)
insert(root, 40)
insert(root, 60)
insert(root, 80)

print("Inorder Traversal (sorted):", end=" ")
inorder(root)
print()

print("Search 40:", "Found" if search(root, 40) else "Not Found")

print("Deleting 20...")
root = delete_node(root, 20)
inorder(root)
print()

print("Deleting 30...")
root = delete_node(root, 30)
inorder(root)
print()
