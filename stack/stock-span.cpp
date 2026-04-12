#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> stockSpan(vector<int> price)
{
    vector<int> ans(price.size(), 0);
    stack<int> st;

    for (int i = 0; i < price.size(); i++)
    {
        while (st.size() > 0 && price[st.top()] <= price[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            ans[i] = i + 1;
        }
        else
        {
            ans[i] = i - st.top();
        }

        st.push(i);
    }

    return ans;
}

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}