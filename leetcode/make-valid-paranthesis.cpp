#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    string minRemoveToMakeValid(string s) {
        string res;
        int cnt = 0;

        // First pass: Remove extra ')'
        for (char c : s) {
            if (c == '(') {
                res += c;
                cnt++;
            } else if (c == ')' && cnt > 0) {
                res += c;
                cnt--;
            } else if (c != ')') {
                res += c;
            }
        }

        // Second pass: Remove extra '('
        string filtered;
        for (int i = res.size() - 1; i >= 0; i--) {
            if (res[i] == '(' && cnt > 0) {
                cnt--;
            } else {
                filtered += res[i];
            }
        }

        reverse(filtered.begin(), filtered.end());
        return filtered;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}