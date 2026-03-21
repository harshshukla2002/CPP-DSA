#include <iostream>
#include <vector>
using namespace std;

int compressString(vector<char> &chars)
{
    int n = chars.size();
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        char ch = chars[i];
        int count = 0;

        while (i < n && ch == chars[i])
        {
            count++;
            i++;
        }

        if (count == 1)
        {
            chars[index++] = ch;
        }
        else
        {
            chars[index++] = ch;
            string str = to_string(count);
            for (char dig : str)
                chars[index++] = dig;
        }
        i--;
    }
    chars.resize(index);
    return index;
}

int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c'};
    return 0;
}