#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size())
            return {};

        unordered_map<char, int> pCount, sCount;

        // Build frequency maps
        for (int i = 0; i < p.size(); i++) {
            pCount[p[i]]++;
            sCount[s[i]]++;
        }

        vector<int> res;
        if (pCount == sCount)
            res.push_back(0);

        int left = 0;

        for (int right = p.size(); right < s.size(); right++) {
            sCount[s[right]]++;
            sCount[s[left]]--;

            if (sCount[s[left]] == 0)
                sCount.erase(s[left]);

            left++;

            if (sCount == pCount)
                res.push_back(left);
        }

        return res;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}