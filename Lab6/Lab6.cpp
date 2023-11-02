
#include <iostream>
#include "List.h"
using namespace std;

class HashTable {
private:
    int size;
    List* table;
    int hashFunction(int key) {
        return key % size;
    }
public:
    HashTable(int tableSize) : size(tableSize){
        table = new List[tableSize];
    }
    ~HashTable() {
        delete[] table;
    }
    void insert(int key, string value) {
        int index = hashFunction(key);
        table[index].pushUp(key, value);
    }
    void deleteByKey(int key) {     
        int index = hashFunction(key);
        if (table[index].deleteByKey(key) == 1) {
            List* newTable = new List[size - 1];
            for (int i = 0; i < index; i++) {
                newTable[i] = table[i];
            }
            for (int i = index + 1; i < size; i++) {
                newTable[i - 1] = table[i];
            }
            table = newTable;
            size--;
        }    
    }
    string findByKey(int key) {
        for (int i = 0; i < size; i++) {
            Node* node = table[i].head;
            while (node) {
                if (node->key == key) {
                    return node->value;;
                }
                node = node->next;
            }
        }
    }
    void print() {
        for (int i = 0; i < size; i++) {
            table[i].print();
         }
    }
};
int main()
{
    HashTable table(5);
    table.insert(5, "1");
    table.insert(6, "2");
    table.insert(7, "3");
    table.insert(8, "4");
    table.insert(9, "5");
    table.deleteByKey(9);
    table.print();
}


