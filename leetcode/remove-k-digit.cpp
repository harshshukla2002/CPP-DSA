#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    string removeKdigits(string num, int k) {
        string stack;

        for (char c : num) {
            while (k > 0 && !stack.empty() && stack.back() > c) {
                k--;
                stack.pop_back();
            }

            stack.push_back(c);
        }

        // If k is still remaining, remove from the end
        while (k > 0 && !stack.empty()) {
            k--;
            stack.pop_back();
        }

        // Remove leading zeros
        int i = 0;

        while (i < stack.size() && stack[i] == '0') {
            i++;
        }

        string res = stack.substr(i);

        return res.empty() ? "0" : res;
    }
};
;

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}