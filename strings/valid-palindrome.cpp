#include <iostream>
using namespace std;

bool isAlphaNumeric(char ch)
{
    if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
        return true;

    return false;
}

bool isPalindrome(string str)
{
    int st = 0, end = str.length() - 1;

    while (st < end)
    {
        if (!isAlphaNumeric(str[st]))
        {
            st++;
            continue;
        }
        if (!isAlphaNumeric(str[end]))
        {
            end--;
            continue;
        }

        if (tolower(str[st]) != tolower(str[end]))
            return false;

        st++, end--;
    }

    return false;
}

int main()
{
    string str = "";
    return 0;
}