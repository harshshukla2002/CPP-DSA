/*
Question: Calculate nCr binomial coefficient for n and r

formula : nCr = n!/r!(n-r)!
*/

#include <iostream>
using namespace std;

int factorial(int num)
{
    int mul = 1;

    for (int i = 1; i <= num; i++)
    {
        mul *= i;
    }

    return mul;
}

int binomialCoefficient(int n, int r)
{
    int nFact = factorial(n);
    int rFact = factorial(r);
    int nmrFact = factorial(n - r);

    return nFact / (rFact * nmrFact);
}

int main()
{
    int res = binomialCoefficient(21, 16);

    cout << "Binomial Coefficient is: " << res << endl;

    return 0;
}