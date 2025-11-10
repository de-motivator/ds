#include <iostream>
#include <stack>
using namespace std;

struct Node {
    char value;
    Node *left, *right;
    Node(char v) : value(v), left(NULL), right(NULL) {}
};

bool isOperator(char c) {
    return c == '~' || c == '&' || c == '|' || c == '>' || c == '=';
}

Node* createTree(string expr) {
    stack<Node*> st;
    for (char c : expr) {
        if (c == ' ') continue;
        if (isalpha(c)) st.push(new Node(c));
        else if (isOperator(c)) {
            Node* node = new Node(c);
            if (c == '~') {
                node->right = st.top(); st.pop();
            } else {
                Node* right = st.top(); st.pop();
                Node* left = st.top(); st.pop();
                node->left = left;
                node->right = right;
            }
            st.push(node);
        }
    }
    return st.top();
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
}

int main() {
    string expr = "PQ&R|"; // postfix form
    Node* root = createTree(expr);
    cout << "Postorder traversal:\n";
    postorder(root);
    cout << endl;
}
