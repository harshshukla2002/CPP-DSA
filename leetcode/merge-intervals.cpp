#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> output;

        output.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];

            int lastIndex = output.size() - 1;

            int previousStart = output[lastIndex][0];
            int previousEnd = output[lastIndex][1];

            if (currentStart <= previousEnd) {
                output[lastIndex][1] = max(previousEnd, currentEnd);

            } else {
                output.push_back(intervals[i]);
            }
        }

        return output;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}