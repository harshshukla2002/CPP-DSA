#include <iostream>
#include <numeric>
using namespace std;

class Solution {
   public:
    bool canShip(vector<int>& weights, int days, int cap) {
        int ships = 1;
        int currCap = cap;

        for (int w : weights) {
            if (currCap - w < 0) {
                ships++;
                currCap = cap;
            }

            currCap -= w;
        }

        return ships <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int res = r;

        while (l <= r) {
            int cap = l + (r - l) / 2;

            if (canShip(weights, days, cap)) {
                res = min(res, cap);
                r = cap - 1;
            } else {
                l = cap + 1;
            }
        }

        return res;
    }
};