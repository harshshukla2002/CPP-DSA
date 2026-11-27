#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int i) {
        if (i == word.size())
            return true;

        int rows = board.size();
        int cols = board[0].size();

        if (r < 0 || c < 0 || r >= rows || c >= cols ||
            board[r][c] != word[i]) {
            return false;
        }

        // Store current character
        char temp = board[r][c];

        // Mark as visited
        board[r][c] = '#';

        bool found = dfs(board, word, r + 1, c, i + 1) ||
                     dfs(board, word, r - 1, c, i + 1) ||
                     dfs(board, word, r, c + 1, i + 1) ||
                     dfs(board, word, r, c - 1, i + 1);

        // Restore original character
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == word[0]) {
                    if (dfs(board, word, r, c, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};