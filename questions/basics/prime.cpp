// Question: Given a number n, determine whether it is a prime number or not.

// brute force-------------
class Solution
{
public:
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;

        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
                return false;
        }

        return true;
    }
};

// optimized version--------
class Solution2
{
public:
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;

        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }

        return true;
    }
};