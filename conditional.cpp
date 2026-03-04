#include <iostream>
using namespace std;

int main()
{
    int age;
    cout << "Enter Age: ";
    cin >> age;

    if (age >= 18)
        cout << "Adult" << endl;
    else
        cout << "Still Young" << endl;

    return 0;
}