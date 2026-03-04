#include <iostream>
using namespace std;

int main()
{
    // primitive data types
    int a = 10;
    char str = 'a';
    string longStr = "harsh";
    bool isError = false;
    float PI = 3.14f;
    double value = 100.9;

    cout << a << " " << str << " " << longStr << " " << isError << " " << PI << " " << value << endl;

    // type casting
    int price = (int)value; // double to int

    cout << price << endl;

    // operators
    int x = 5;
    int y = 2;

    cout << "divide of int: " << (x / y) << endl; // it gives 2 not 2.5

    // if we need 2.5 then change 1 to double type of float type
    cout << "divide of double: " << (5 / (double)2) << endl; // it gives 2.5

    return 0;
}