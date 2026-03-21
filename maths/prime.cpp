#include <iostream>
using namespace std;

bool isPrime(int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int countPrime(int num)
{
    vector<bool> isPrime(num + 1, true);
    int count = 0;

    for (int i = 2; i < num; i++)
    {
        if (isPrime[i])
        {
            count++;

            for (int j = i * 2; j < num; j += i)
                isPrime[j] = false;
        }
    }

    return count;
}

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}