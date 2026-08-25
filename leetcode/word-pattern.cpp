#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;

        // Split string into words
        while (ss >> word) {
            words.push_back(word);
        }

        // Number of characters and words must match
        if (pattern.length() != words.size()) {
            return false;
        }

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern[i];
            string w = words[i];

            // Check character -> word mapping
            if (charToWord.count(c) && charToWord[c] != w) {
                return false;
            }

            // Check word -> character mapping
            if (wordToChar.count(w) && wordToChar[w] != c) {
                return false;
            }

            charToWord[c] = w;
            wordToChar[w] = c;
        }

        return true;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}