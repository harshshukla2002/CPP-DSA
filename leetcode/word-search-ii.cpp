#include <iostream>
using namespace std;

class TrieNode {
   public:
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};

class Solution {
   private:
    TrieNode* root = new TrieNode();

    // Build the Trie
    void insert(string& word) {
        TrieNode* cur = root;

        for (char c : word) {
            if (!cur->children.count(c)) {
                cur->children[c] = new TrieNode();
            }

            cur = cur->children[c];
        }

        cur->isWord = true;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node,
             string& word, vector<vector<bool>>& visited,
             vector<string>& result) {
        int ROWS = board.size();
        int COLS = board[0].size();

        // Boundary and visited checks
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || visited[r][c]) {
            return;
        }

        char ch = board[r][c];

        // Prune paths that are not Trie prefixes
        if (!node->children.count(ch)) {
            return;
        }

        node = node->children[ch];

        visited[r][c] = true;
        word.push_back(ch);

        // Found a complete word
        if (node->isWord) {
            result.push_back(word);
            node->isWord = false;  // Avoid duplicate results
        }

        // Explore all four directions
        dfs(board, r + 1, c, node, word, visited, result);
        dfs(board, r - 1, c, node, word, visited, result);
        dfs(board, r, c + 1, node, word, visited, result);
        dfs(board, r, c - 1, node, word, visited, result);

        // Backtrack
        word.pop_back();
        visited[r][c] = false;
    }

   public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        if (board.empty() || board[0].empty()) {
            return {};
        }

        // Insert all words into the Trie
        for (string& word : words) {
            insert(word);
        }

        int ROWS = board.size();
        int COLS = board[0].size();

        vector<string> result;
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

        string word = "";

        // Start DFS from every cell
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                dfs(board, r, c, root, word, visited, result);
            }
        }

        return result;
    }
};