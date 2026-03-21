#include <iostream>
using namespace std;

string reverseWord(string str)
{
    int n = str.length();
    string ans = "";

    reverse(str.begin(), str.end());

    for (int i = 0; i < n; i++)
    {
        string word = "";

        while (i < n && str[i] != ' ')
        {
            word += str[i];
            i++;
        }

        reverse(word.begin(), word.end());

        if (word.length() > 0)
            ans += " " + word;
    }

    return ans.substr(1);
}

int main()
{
    string s = "the sky is blue";
    return 0;
}