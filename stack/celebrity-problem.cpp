#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int getCelebrity(vector<vector<int>> &arr)
{
    int n = arr.size();
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    while (st.size() > 1)
    {
        int i = st.top();
        st.pop();

        int j = st.top();
        st.pop();

        if (arr[i][j] == 0)
        {
            st.push(i);
        }
        else
        {
            st.push(j);
        }
    }

    int celeb = st.top();

    for (int i = 0; i < n; i++)
    {
        if ((i != celeb) && (arr[i][celeb] == 0 || arr[i][celeb] == 1))
        {
            return -1;
        }
    }

    return celeb;
}

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}