#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    string alienOrder(vector<string>& words) {
        // Build adjacency list
        unordered_map<char, unordered_set<char>> adj;

        // Add every character
        for (string& word : words) {
            for (char c : word) {
                adj[c] = {};
            }
        }

        // Build edges by comparing adjacent words
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            int minLen = min(w1.size(), w2.size());

            // Invalid case:
            // ["abc", "ab"]
            if (w1.size() > w2.size() &&
                w1.substr(0, minLen) == w2) {
                return "";
            }

            // Find first different character
            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }

        // false = currently in path
        // true  = completely processed
        unordered_map<char, bool> visit;

        vector<char> res;

        function<bool(char)> dfs = [&](char c) {
            if (visit.count(c)) {
                return visit[c];
            }

            // Mark as currently visiting
            visit[c] = false;

            for (char nei : adj[c]) {
                if (dfs(nei)) {
                    return true;
                }
            }

            // Finished processing
            visit[c] = true;
            res.push_back(c);

            return false;
        };

        // DFS for every character
        for (auto& [c, neighbors] : adj) {
            if (dfs(c)) {
                return "";
            }
        }

        // DFS gives reverse topological order
        reverse(res.begin(), res.end());

        return string(res.begin(), res.end());
    }
};