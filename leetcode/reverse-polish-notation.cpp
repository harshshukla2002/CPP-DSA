#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {
            if (token == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b + a);
            } else if (token == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            } else if (token == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b * a);
            } else if (token == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b / a);  // C++ truncates toward zero
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}