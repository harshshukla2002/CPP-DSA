#include <iostream>
using namespace std;

class Solution {
   public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        // Min heap: {capital required, profit}
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minCapital;

        // Max heap: profits of projects we can afford
        priority_queue<int> maxProfit;

        // Store all projects
        for (int i = 0; i < profits.size(); i++) {
            minCapital.push({capital[i], profits[i]});
        }

        // Pick at most k projects
        for (int i = 0; i < k; i++) {
            // Move all affordable projects into max heap
            while (!minCapital.empty() && minCapital.top().first <= w) {
                int c = minCapital.top().first;
                int p = minCapital.top().second;

                minCapital.pop();

                maxProfit.push(p);
            }

            // No project can be afforded
            if (maxProfit.empty()) {
                break;
            }

            // Choose project with maximum profit
            w += maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}