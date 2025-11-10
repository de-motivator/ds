class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def is_operator(c):
    return c in ['~', '&', '|', '>', '=']

def create_tree(expr):
    stack = []
    for c in expr:
        if c == ' ':
            continue
        elif c.isalpha():  # operand
            stack.append(Node(c))
        elif is_operator(c):
            node = Node(c)
            if c == '~':  # unary operator
                node.right = stack.pop()
            else:  # binary operator
                right = stack.pop()
                left = stack.pop()
                node.right = right
                node.left = left
            stack.append(node)
    return stack[-1]  # root node

# Postorder traversal to verify
def postorder(root):
    if not root:
        return
    postorder(root.left)
    postorder(root.right)
    print(root.value, end=' ')

# Example usage
expr = "PQ&R|"   # equivalent to (P & Q) | R in postfix form
root = create_tree(expr)
print("Postorder traversal of tree:")
postorder(root)
