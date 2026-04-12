#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> previousSmallerElement(vector<int> arr)
{
    vector<int> ans;
    stack<int> st;

    for (int i = 0; i < arr.size(); i++)
    {
        while (st.size() > 0 && st.top() >= arr[i])
            st.pop();

        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();

        st.push(arr[i]);
    }

    return ans;
}

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}