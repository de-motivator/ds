#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Bucket {
public:
    int depth;
    int size;
    unordered_map<int, string> items;
    Bucket(int d, int s) : depth(d), size(s) {}
    bool isFull() { return items.size() >= size; }
};

class ExtendibleHashTable {
    int globalDepth, bucketSize;
    vector<Bucket*> directory;

    int hashFunc(int key) { return key & ((1 << globalDepth) - 1); }

public:
    ExtendibleHashTable(int size) {
        bucketSize = size;
        globalDepth = 1;
        directory.push_back(new Bucket(1, size));
        directory.push_back(new Bucket(1, size));
    }

    void doubleDirectory() {
        directory.insert(directory.end(), directory.begin(), directory.end());
        globalDepth++;
        cout << "Directory doubled. Global depth: " << globalDepth << endl;
    }

    void insert(int key, string value) {
        int idx = hashFunc(key);
        Bucket* bucket = directory[idx];

        if (bucket->items.find(key) != bucket->items.end()) {
            bucket->items[key] = value;
            return;
        }

        if (bucket->isFull()) {
            cout << "Splitting bucket at index " << idx << endl;
            splitBucket(idx);
            insert(key, value);
        } else {
            bucket->items[key] = value;
            cout << "Inserted (" << key << ":" << value << ") in bucket " << idx << endl;
        }
    }

    void splitBucket(int index) {
        Bucket* bucket = directory[index];
        bucket->depth++;

        if (bucket->depth > globalDepth) doubleDirectory();

        Bucket* newBucket = new Bucket(bucket->depth, bucketSize);
        unordered_map<int, string> oldItems = bucket->items;
        bucket->items.clear();

        for (auto& kv : oldItems) {
            int newIdx = hashFunc(kv.first);
            if (kv.first & (1 << (bucket->depth - 1)))
                newBucket->items[kv.first] = kv.second;
            else
                bucket->items[kv.first] = kv.second;
        }

        for (int i = 0; i < directory.size(); i++) {
            if (directory[i] == bucket && (i & (1 << (bucket->depth - 1))))
                directory[i] = newBucket;
        }
    }

    void search(int key) {
        int idx = hashFunc(key);
        if (directory[idx]->items.count(key))
            cout << "Found: " << directory[idx]->items[key] << endl;
        else
            cout << "Not found.\n";
    }

    void remove(int key) {
        int idx = hashFunc(key);
        if (directory[idx]->items.erase(key))
            cout << "Deleted key " << key << endl;
        else
            cout << "Key not found.\n";
    }

    void display() {
        cout << "\n--- Hash Table State ---\n";
        for (int i = 0; i < directory.size(); i++) {
            cout << "Bucket " << i << " (Depth=" << directory[i]->depth << "): ";
            for (auto& kv : directory[i]->items)
                cout << "(" << kv.first << ":" << kv.second << ") ";
            cout << endl;
        }
    }
};

int main() {
    ExtendibleHashTable ht(2);
    ht.insert(5, "A");
    ht.insert(7, "B");
    ht.insert(13, "C");
    ht.insert(9, "D");
    ht.display();
    ht.search(7);
    ht.remove(13);
    ht.display();
}

