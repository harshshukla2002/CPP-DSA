#include <iostream>
#include <list>
using namespace std;

class MyHashMap {
   private:
    static const int SIZE = 1000;

    vector<list<pair<int, int>>> table;

    int hash(int key) { return key % SIZE; }

   public:
    MyHashMap() { table.resize(SIZE); }

    void put(int key, int value) {
        int index = hash(key);

        // Check if key already exists
        for (auto& p : table[index]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }

        // Key doesn't exist, insert it
        table[index].push_back({key, value});
    }

    int get(int key) {
        int index = hash(key);

        for (auto& p : table[index]) {
            if (p.first == key) {
                return p.second;
            }
        }

        return -1;
    }

    void remove(int key) {
        int index = hash(key);

        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}