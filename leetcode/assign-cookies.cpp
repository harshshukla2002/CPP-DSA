#include <iostream>
#include <map>
using namespace std;

class Solution {
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;

        while (i < g.size() && j < s.size()) {
            // Cookie is too small for this child
            while (j < s.size() && g[i] > s[j]) {
                j++;
            }

            if (j == s.size()) {
                break;
            }

            // Assign cookie to child
            i++;
            j++;
        }

        return i;
    }
};