#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        string res = "";
        int resLen = 0;

        for (int i = 0; i < s.length(); i++) {
            // Odd length palindrome
            int l = i, r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if ((r - l + 1) > resLen) {
                    res = s.substr(l, r - l + 1);
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }

            // Even length palindrome
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if ((r - l + 1) > resLen) {
                    res = s.substr(l, r - l + 1);
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return res;
    }
};

class Solution {
   public:
    int countPali(string s, int l, int r) {
        int res = 0;

        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            res++;
            l--;
            r++;
        }

        return res;
    }

    int countSubstrings(string s) {
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            count += countPali(s, i, i);
            count += countPali(s, i, i + 1);
        }

        return count;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}