#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    struct HashNode {
        int key;
        int value;
        bool occupied;
        HashNode() : key(0), value(0), occupied(false) {}
    };

    HashNode table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    int findNextFreeIndex(int index) {
        while (table[index].occupied) {
            index = (index + 1) % TABLE_SIZE;
        }
        return index;
    }

public:
    void insert(int key, int value) {
        int hashIndex = hashFunction(key);

        if (table[hashIndex].occupied) {
            hashIndex = findNextFreeIndex(hashIndex);
        }

        table[hashIndex].key = key;
        table[hashIndex].value = value;
        table[hashIndex].occupied = true;

        cout << "Inserted (" << key << ", " << value << ") at index " << hashIndex << endl;
    }

    int search(int key) {
        int hashIndex = hashFunction(key);

        while (table[hashIndex].occupied) {
            if (table[hashIndex].key == key) {
                return table[hashIndex].value;
            }
            hashIndex = (hashIndex + 1) % TABLE_SIZE;
        }

        return -1; // Not found
    }

    void remove(int key) {
        int hashIndex = hashFunction(key);

        while (table[hashIndex].occupied) {
            if (table[hashIndex].key == key) {
                table[hashIndex].occupied = false;
                cout << "Removed key " << key << " from index " << hashIndex << endl;
                return;
            }
            hashIndex = (hashIndex + 1) % TABLE_SIZE;
        }

        cout << "Key " << key << " not found" << endl;
    }

    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i].occupied) {
                cout << "Index " << i << ": (" << table[i].key << ", " << table[i].value << ")" << endl;
            } else {
                cout << "Index " << i << ": Empty" << endl;
            }
        }
    }
};

int main() {
    HashTable hashTable;

    int data[] = {12, 22, 34, 55, 67, 99, 33, 42};
    int n = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++) {
        hashTable.insert(data[i], data[i]);
    }

    hashTable.display();

    int keyToSearch = 31;
    int value = hashTable.search(keyToSearch);
    if (value != -1) {
        cout << "Value of key " << keyToSearch << " is " << value << endl;
    } else {
        cout << "Key " << keyToSearch << " not found" << endl;
    }

    int keyToRemove = 99;
    hashTable.remove(keyToRemove);
    hashTable.display();

    return 0;
}
