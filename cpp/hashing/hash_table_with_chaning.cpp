#include <iostream>
#include <list>
using namespace std;

const int SIZE = 10;
list<pair<int, string>> table[SIZE];

int hashFunc(int key) { return key % SIZE; }

void insert(int key, string value) {
    int i = hashFunc(key);
    table[i].push_back({key, value});
    cout << "Inserted (" << key << ", " << value << ") at " << i << endl;
}

void search(int key) {
    int i = hashFunc(key);
    for (auto &p : table[i])
        if (p.first == key) { cout << "Found: " << p.second << endl; return; }
    cout << "Not found\n";
}

void del(int key) {
    int i = hashFunc(key);
    for (auto it = table[i].begin(); it != table[i].end(); ++it)
        if (it->first == key) { table[i].erase(it); cout << "Deleted\n"; return; }
    cout << "Not found\n";
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        for (auto &p : table[i]) cout << "(" << p.first << "," << p.second << ") -> ";
        cout << "NULL\n";
    }
}

int main() {
    insert(11,"A"); insert(21,"B"); insert(31,"C");
    display();
    search(21);
    del(11);
    display();
}
