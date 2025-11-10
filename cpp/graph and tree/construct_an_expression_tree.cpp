#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Node structure
struct Node {
    char data;
    Node* left;
    Node* right;
};

// Create a new node
Node* newNode(char data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Construct expression tree from prefix
Node* constructTreeFromPrefix(string prefix) {
    stack<Node*> st;
    // Traverse from right to left
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isalnum(ch)) {
            st.push(newNode(ch));  // Operand → push
        } else {                  // Operator → pop two and make new tree
            Node* node = newNode(ch);
            node->left = st.top(); st.pop();
            node->right = st.top(); st.pop();
            st.push(node);
        }
    }
    return st.top(); // Root of expression tree
}

// Postorder traversal (non-recursive)
void postorderNonRecursive(Node* root) {
    if (root == NULL) return;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* curr = s1.top(); s1.pop();
        s2.push(curr);

        if (curr->left)
            s1.push(curr->left);
        if (curr->right)
            s1.push(curr->right);
    }

    cout << "Postorder Traversal: ";
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
    cout << endl;
}

// Delete entire tree
void deleteTree(Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    string prefix = "+--a*bc/def";
    cout << "Prefix Expression: " << prefix << endl;

    Node* root = constructTreeFromPrefix(prefix);

    postorderNonRecursive(root);

    deleteTree(root);
    cout << "Tree deleted successfully.\n";

    return 0;
}
