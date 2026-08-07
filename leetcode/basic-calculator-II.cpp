#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int calculate(string s) {
        stack<long long> st;

        long long num = 0;
        char op = '+';

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
                if (op == '+')
                    st.push(num);

                else if (op == '-')
                    st.push(-num);

                else if (op == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                }

                else if (op == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }

                op = s[i];
                num = 0;
            }
        }

        long long ans = 0;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}