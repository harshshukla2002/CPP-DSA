#include <iostream>
#include <list>
using namespace std;

class RandomizedSet {
   private:
    unordered_map<int, int> numMap;  // value -> index
    vector<int> numList;             // values

   public:
    RandomizedSet() {}

    bool insert(int val) {
        if (numMap.count(val)) {
            return false;
        }

        numMap[val] = numList.size();
        numList.push_back(val);

        return true;
    }

    bool remove(int val) {
        if (!numMap.count(val)) {
            return false;
        }

        int idx = numMap[val];
        int lastVal = numList.back();

        // Move last element to the position of val
        numList[idx] = lastVal;

        // Update last element's index
        numMap[lastVal] = idx;

        // Remove last element
        numList.pop_back();

        // Remove val from map
        numMap.erase(val);

        return true;
    }

    int getRandom() { return numList[rand() % numList.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}