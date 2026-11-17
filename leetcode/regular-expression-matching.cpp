#include <iostream>
#include <map>
#include <numeric>
using namespace std;

class Solution {
   public:
    unordered_map<string, bool> cache;

    bool dfs(int i, int j, string& s, string& p) {
        string key = to_string(i) + "," + to_string(j);

        if (cache.count(key)) {
            return cache[key];
        }

        // Both strings are completely matched
        if (i >= s.size() && j >= p.size()) {
            return true;
        }

        // Pattern is exhausted but string is not
        if (j >= p.size()) {
            return false;
        }

        bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        // Handle '*'
        if (j + 1 < p.size() && p[j + 1] == '*') {
            cache[key] = dfs(i, j + 2, s, p) || (match && dfs(i + 1, j, s, p));

            return cache[key];
        }

        // Normal character or '.'
        if (match) {
            cache[key] = dfs(i + 1, j + 1, s, p);
            return cache[key];
        }

        cache[key] = false;
        return false;
    }

    bool isMatch(string s, string p) {
        cache.clear();
        return dfs(0, 0, s, p);
    }
};