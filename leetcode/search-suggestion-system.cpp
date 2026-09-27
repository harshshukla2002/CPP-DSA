#include <iostream>
using namespace std;

class Solution {
   public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;

        // Sort products lexicographically
        sort(products.begin(), products.end());

        int l = 0;
        int r = products.size() - 1;

        for (int i = 0; i < searchWord.size(); i++) {
            char c = searchWord[i];

            // Move left pointer until the product matches
            while (l <= r && (products[l].size() <= i || products[l][i] != c)) {
                l++;
            }

            // Move right pointer until the product matches
            while (l <= r && (products[r].size() <= i || products[r][i] != c)) {
                r--;
            }

            res.push_back({});

            // Add at most 3 matching products
            int remain = max(0, r - l + 1);

            for (int j = 0; j < min(3, remain); j++) {
                res.back().push_back(products[l + j]);
            }
        }

        return res;
    }
};