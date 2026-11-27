#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> res;

        unordered_map<char, string> digitToChar = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        function<void(int, string)> backtrack = [&](int i, string curStr) {
            if (i == digits.size()) {
                res.push_back(curStr);
                return;
            }

            for (char c : digitToChar[digits[i]]) {
                backtrack(i + 1, curStr + c);
            }
        };

        backtrack(0, "");

        return res;
    }
};