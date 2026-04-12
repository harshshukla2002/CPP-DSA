#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), 0);

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (st.size() > 0 && st.top() <= arr[i])
            st.pop();

        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }

        st.push(arr[i]);
    }

    return ans;
}

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}