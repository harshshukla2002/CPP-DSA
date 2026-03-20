#include <iostream>
#include <string>
using namespace std;

int main()
{
    // using char array
    char str[100];
    char str2[] = {'a', 'b', 'c', '\0'};

    // to get input in string we use cin.getline(var name, length, delimiter)
    // delimiter is used to stop with specific symbol
    cin.getline(str, 100, '$');

    // using string library
    string st = "hello";

    // get length in string
    cout << st.length() << endl;
    return 0;
}