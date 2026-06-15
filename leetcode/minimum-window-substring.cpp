#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        // add all the chars need to make valid string
        for (char c : t) {
            need[c]++;
        }

        int required = need.size();
        int have = 0;

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];

            window[ch]++;

            // if char is needed and count is also same
            if (need.count(ch) && window[ch] == need[ch]) {
                have++;
            }

            // if it is valid and we can make smaller
            while (have == required) {
                // get smallest length
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                // if count is present and char is already removed from window
                if (need.count(leftChar) && window[leftChar] < need[leftChar]) {
                    have--;
                }

                left++;
            }
        }

        return minLen == INT_MAX
                   ? ""
                   : s.substr(start, minLen);
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}