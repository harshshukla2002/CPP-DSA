#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    vector<string> res;
    string curr;

    void backtrack(int open, int close, int n) {
        // Base case
        if (open == n && close == n) {
            res.push_back(curr);
            return;
        }

        // Add '(' if we still can
        if (open < n) {
            curr.push_back('(');
            backtrack(open + 1, close, n);
            curr.pop_back();  // Backtrack
        }

        // Add ')' if it won't make the string invalid
        if (close < open) {
            curr.push_back(')');
            backtrack(open, close + 1, n);
            curr.pop_back();  // Backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n);
        return res;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}