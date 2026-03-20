#include <iostream>
using namespace std;

bool isFreqSame(int freq[], int wFreq[])
{
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != wFreq[i])
            return false;
    }

    return true;
}

bool permutationString(string s1, string s2)
{
    int freq[26] = {0};

    for (int i = 0; i < s1.length(); i++)
    {
        freq[s1[i] - 'a']++;
    }

    int wSize = s1.length();

    for (int i = 0; i < s2.length(); i++)
    {
        int wIndex = 0, index = i;
        int wFreq[26] = {0};

        while (wIndex < wSize && index < s2.length())
        {
            wFreq[s2[index] - 'a']++;
            index++, wIndex++;
        }
        if (isFreqSame(freq, wFreq))
            return true;
    }

    return false;
}

int main()
{
    string s1 = "";
    string s2 = "";
    return 0;
}