#include <iostream>
using namespace std;

class TrieNode {
   public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isWord = false;
    }
};

class WordDictionary {
   private:
    TrieNode* root;

    bool dfs(int i, string& word, TrieNode* node) {
        // We have processed the entire word
        if (i == word.size()) {
            return node->isWord;
        }

        char c = word[i];

        // Wildcard: try every available child
        if (c == '.') {
            for (int j = 0; j < 26; j++) {
                if (node->children[j] != nullptr) {
                    if (dfs(i + 1, word, node->children[j])) {
                        return true;
                    }
                }
            }
            return false;
        }

        // Normal character
        int idx = c - 'a';

        if (node->children[idx] == nullptr) {
            return false;
        }

        return dfs(i + 1, word, node->children[idx]);
    }

   public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* cur = root;

        for (char c : word) {
            int idx = c - 'a';

            if (cur->children[idx] == nullptr) {
                cur->children[idx] = new TrieNode();
            }

            cur = cur->children[idx];
        }

        cur->isWord = true;
    }

    bool search(string word) { return dfs(0, word, root); }
};