#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        // If endWord is not in the word list, no transformation is possible
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        unordered_map<string, vector<string>> nei;

        // Include beginWord so it can be part of the graph
        wordList.push_back(beginWord);

        int L = beginWord.size();

        // Build the wildcard-pattern graph
        for (string& word : wordList) {
            for (int i = 0; i < L; i++) {
                string pattern = word;
                pattern[i] = '*';
                nei[pattern].push_back(word);
            }
        }

        queue<string> q;
        unordered_set<string> visited;

        q.push(beginWord);
        visited.insert(beginWord);

        int res = 1;

        while (!q.empty()) {
            int size = q.size();

            // Process one BFS level at a time
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();

                if (word == endWord) {
                    return res;
                }

                for (int j = 0; j < L; j++) {
                    string pattern = word;
                    pattern[j] = '*';

                    for (const string& neiWord : nei[pattern]) {
                        if (visited.find(neiWord) == visited.end()) {
                            visited.insert(neiWord);
                            q.push(neiWord);
                        }
                    }
                }
            }

            res++;
        }

        return 0;
    }
};