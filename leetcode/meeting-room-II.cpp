#include <iostream>
using namespace std;

class Solution {
   public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> start;
        vector<int> end;

        // Store start and end times separately
        for (auto& interval : intervals) {
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }

        // Sort both arrays
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int res = 0;
        int count = 0;

        int s = 0;
        int e = 0;

        while (s < n) {
            // A new meeting starts before the earliest
            // current meeting ends
            if (start[s] < end[e]) {
                s++;
                count++;

                res = max(res, count);
            } else {
                // A meeting has ended, so its room can be reused
                e++;
                count--;
            }
        }

        return res;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}