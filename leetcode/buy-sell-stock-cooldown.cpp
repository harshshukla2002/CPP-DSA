#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    int solve(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (i >= prices.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;

        if (buy) {
            int buyStock = -prices[i] + solve(i + 1, 0, prices, dp);
            int skip = solve(i + 1, 1, prices, dp);

            profit = max(buyStock, skip);
        } else {
            int sellStock = prices[i] + solve(i + 2, 1, prices, dp);
            int hold = solve(i + 1, 0, prices, dp);

            profit = max(sellStock, hold);
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, 1, prices, dp);
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}