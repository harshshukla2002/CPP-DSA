/* Question: Given a positive integer, n. Find the factorial of n.

 Examples :
 Input: n = 5
 Output: 120
 Explanation: 1 x 2 x 3 x 4 x 5 = 120
*/

class Solution
{
public:
    int factorial(int n)
    {
        int res = 1;
        for (int i = 1; i <= n; i++)
        {
            res *= i;
        }

        return res;
    }
};