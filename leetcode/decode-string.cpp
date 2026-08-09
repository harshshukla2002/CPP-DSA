#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    string decodeString(string s) {
        vector<string> stack;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                stack.push_back(string(1, s[i]));
            } else {
                // Build substring
                string substr = "";

                while (stack.back() != "[") {
                    substr = stack.back() + substr;
                    stack.pop_back();
                }

                // Remove "["
                stack.pop_back();

                // Build number
                string k = "";

                while (!stack.empty() && isdigit(stack.back()[0])) {
                    k = stack.back() + k;
                    stack.pop_back();
                }

                // Repeat substring
                int count = stoi(k);

                string decoded = "";

                for (int j = 0; j < count; j++) {
                    decoded += substr;
                }

                stack.push_back(decoded);
            }
        }

        // Build final answer
        string ans = "";

        for (string str : stack) {
            ans += str;
        }

        return ans;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}