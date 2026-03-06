/*
Question: Given a number return the sum of every digit in number
*/

#include <iostream>
using namespace std;

int sumOfDigits(int num)
{
    int sum = 0;

    while (num > 0)
    {
        int digit = num % 10;
        num = num / 10;
        sum += digit;
    }

    return sum;
}

int main()
{
    int ans = sumOfDigits(146);
    cout << "Sum of digits is: " << ans << endl;
    return 0;
}