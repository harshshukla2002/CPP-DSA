#include <iostream>
#include <map>
#include <numeric>
using namespace std;

class Solution {
   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int res = points.size();
        int prevEnd = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            int currStart = points[i][0];
            int currEnd = points[i][1];

            if (currStart <= prevEnd) {
                res--;
                prevEnd = min(currEnd, prevEnd);
            } else {
                prevEnd = currEnd;
            }
        }

        return res;
    }
};