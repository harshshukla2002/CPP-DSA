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
            int start = intervals[i][0];
            int end = intervals[i][1];

            int lastEnd = output.back()[1];

            if (start <= lastEnd) {
                output.back()[1] = max(lastEnd, end);
            } else {
                output.push_back({start, end});
            }
        }

        return output;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}