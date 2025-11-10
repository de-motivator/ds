#include <iostream>
#include <string>
using namespace std;

// Node structure for BST
struct Node {
    string city;
    int population;
    Node* left;
    Node* right;
};

// Create a new node
Node* newNode(string city, int population) {
    Node* node = new Node();
    node->city = city;
    node->population = population;
    node->left = node->right = NULL;
    return node;
}

// Insert a new city
Node* insert(Node* root, string city, int population) {
    if (root == NULL)
        return newNode(city, population);

    if (city < root->city)
        root->left = insert(root->left, city, population);
    else if (city > root->city)
        root->right = insert(root->right, city, population);
    else
        cout << "City already exists!\n";

    return root;
}

// Find the minimum node (used in delete)
Node* findMin(Node* node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

// Delete a city
Node* deleteCity(Node* root, string city) {
    if (root == NULL)
        return root;

    if (city < root->city)
        root->left = deleteCity(root->left, city);
    else if (city > root->city)
        root->right = deleteCity(root->right, city);
    else {
        // Node with one or zero child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        Node* temp = findMin(root->right);
        root->city = temp->city;
        root->population = temp->population;
        root->right = deleteCity(root->right, temp->city);
    }
    return root;
}

// Update a city's population
void updatePopulation(Node* root, string city, int newPop) {
    if (root == NULL) {
        cout << "City not found.\n";
        return;
    }
    if (city < root->city)
        updatePopulation(root->left, city, newPop);
    else if (city > root->city)
        updatePopulation(root->right, city, newPop);
    else {
        root->population = newPop;
        cout << "Population updated for " << city << " to " << newPop << endl;
    }
}

// Display cities in ascending order
void displayAscending(Node* root) {
    if (root != NULL) {
        displayAscending(root->left);
        cout << root->city << " (" << root->population << ")\n";
        displayAscending(root->right);
    }
}

// Display cities in descending order
void displayDescending(Node* root) {
    if (root != NULL) {
        displayDescending(root->right);
        cout << root->city << " (" << root->population << ")\n";
        displayDescending(root->left);
    }
}

// Search city and count comparisons
int searchCity(Node* root, string city) {
    int comparisons = 0;
    while (root != NULL) {
        comparisons++;
        if (root->city == city) {
            cout << city << " found with population " << root->population << endl;
            return comparisons;
        }
        if (city < root->city)
            root = root->left;
        else
            root = root->right;
    }
    cout << city << " not found.\n";
    return comparisons;
}

// Find maximum possible comparisons (tree height)
int findHeight(Node* root) {
    if (root == NULL) return 0;
    int leftH = findHeight(root->left);
    int rightH = findHeight(root->right);
    return max(leftH, rightH) + 1;
}

// Main program
int main() {
    Node* root = NULL;
    root = insert(root, "Mumbai", 20000000);
    insert(root, "Pune", 6000000);
    insert(root, "Delhi", 19000000);
    insert(root, "Chennai", 9000000);

    cout << "\nCities in Ascending Order:\n";
    displayAscending(root);

    cout << "\nCities in Descending Order:\n";
    displayDescending(root);

    cout << "\nSearching for 'Pune'...\n";
    int cmp = searchCity(root, "Pune");
    cout << "Comparisons made: " << cmp << endl;

    cout << "\nUpdating population of 'Delhi'...\n";
    updatePopulation(root, "Delhi", 20000000);

    cout << "\nDeleting 'Chennai'...\n";
    root = deleteCity(root, "Chennai");

    cout << "\nCities after deletion:\n";
    displayAscending(root);

    cout << "\nMaximum comparisons (worst case): " << findHeight(root) << endl;

    return 0;
}
