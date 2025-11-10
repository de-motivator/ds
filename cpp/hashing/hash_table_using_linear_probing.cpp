#include <iostream>
using namespace std;

const int SIZE = 10;
int table[SIZE];
bool occupied[SIZE] = {false};

int hashFunc(int key) {
    return key % SIZE;
}

void insertKey(int key) {
    int i = hashFunc(key);
    for (int j = 0; j < SIZE; j++) {
        int idx = (i + j) % SIZE;
        if (!occupied[idx]) {
            table[idx] = key;
            occupied[idx] = true;
            cout << "Inserted " << key << " at index " << idx << endl;
            return;
        }
    }
    cout << "Hash table full!\n";
}

void searchKey(int key) {
    int i = hashFunc(key);
    for (int j = 0; j < SIZE; j++) {
        int idx = (i + j) % SIZE;
        if (occupied[idx] && table[idx] == key) {
            cout << "Found " << key << " at index " << idx << endl;
            return;
        }
    }
    cout << "Key not found\n";
}

void deleteKey(int key) {
    int i = hashFunc(key);
    for (int j = 0; j < SIZE; j++) {
        int idx = (i + j) % SIZE;
        if (occupied[idx] && table[idx] == key) {
            occupied[idx] = false;
            cout << "Deleted " << key << " from index " << idx << endl;
            return;
        }
    }
    cout << "Key not found\n";
}

void display() {
    cout << "\n--- Hash Table ---\n";
    for (int i = 0; i < SIZE; i++) {
        if (occupied[i]) cout << i << ": " << table[i] << endl;
        else cout << i << ": EMPTY\n";
    }
}

int main() {
    insertKey(11);
    insertKey(21);
    insertKey(31);
    insertKey(4);
    display();
    searchKey(21);
    deleteKey(31);
    display();
    return 0;
}
