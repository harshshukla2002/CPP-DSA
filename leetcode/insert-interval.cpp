#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        for (int i = 0; i < intervals.size(); i++) {
            // New interval comes before current interval
            if (newInterval[1] < intervals[i][0]) {
                res.push_back(newInterval);

                while (i < intervals.size()) {
                    res.push_back(intervals[i]);
                    i++;
                }

                return res;
            }
            // New interval comes after current interval
            else if (newInterval[0] > intervals[i][1]) {
                res.push_back(intervals[i]);
            }
            // Overlapping intervals
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        res.push_back(newInterval);

        return res;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}