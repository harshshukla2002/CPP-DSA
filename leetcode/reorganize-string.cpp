#include <iostream>
using namespace std;

class Solution {
   public:
    string reorganizeString(string s) {
        // Count frequency of each character
        unordered_map<char, int> count;

        for (char c : s) {
            count[c]++;
        }

        // Max heap: {frequency, character}
        priority_queue<pair<int, char>> maxHeap;

        for (auto& [ch, cnt] : count) {
            maxHeap.push({cnt, ch});
        }

        string res = "";

        // Previous character that we cannot use immediately
        pair<int, char> prev = {0, '#'};

        while (!maxHeap.empty() || prev.first > 0) {
            // If nothing is available but previous character exists,
            // we cannot reorganize the string.
            if (maxHeap.empty() && prev.first > 0) {
                return "";
            }

            // Take the most frequent character
            auto [cnt, ch] = maxHeap.top();
            maxHeap.pop();

            // Add character to result
            res += ch;

            // We used one occurrence
            cnt--;

            // Put previous character back into heap
            if (prev.first > 0) {
                maxHeap.push(prev);
            }

            // Current character becomes previous
            if (cnt > 0) {
                prev = {cnt, ch};
            } else {
                prev = {0, '#'};
            }
        }

        return res;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}