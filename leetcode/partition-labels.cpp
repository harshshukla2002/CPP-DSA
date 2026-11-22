#include <iostream>
#include <map>
using namespace std;

class Solution {
   public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndex;

        // Store the last occurrence of every character
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i]] = i;
        }

        vector<int> res;
        int size = 0;
        int end = 0;

        for (int i = 0; i < s.size(); i++) {
            size++;

            end = max(end, lastIndex[s[i]]);

            if (i == end) {
                res.push_back(size);
                size = 0;
            }
        }

        return res;
    }
};