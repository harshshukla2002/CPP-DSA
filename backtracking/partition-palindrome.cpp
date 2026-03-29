#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string s)
{
    string s2 = s;
    reverse(s.begin(), s.end());

    return s2 == s;
}

void getAllParts(string str, vector<string> &part, vector<vector<string>> &ans)
{
    if (str.size() == 0)
    {
        ans.push_back(part);
        return;
    }

    for (int i = 0; i < str.size(); i++)
    {
        string s = str.substr(0, i + 1);

        if (isPalindrome(s))
        {
            part.push_back(s);
            getAllParts(str.substr(i + 1), part, ans);
            part.pop_back();
        }
    }
}

vector<vector<string>> partition(string str)
{
    vector<vector<string>> ans;
    vector<string> part;

    getAllParts(str, part, ans);

    return ans;
}

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}