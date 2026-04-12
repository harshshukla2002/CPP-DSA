#include <iostream>
#include <stack>
using namespace std;

bool isValid(string str)
{
    stack<char> st;

    for (char c : str)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.size() == 0)
                return false;

            if (c == ')' && st.top() == '(' || c == '}' && st.top() == '{' || c == ']' && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return st.size() == 0;
}

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}