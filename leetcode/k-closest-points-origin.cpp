#include <iostream>
using namespace std;

class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Min heap: {distance, x, y}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            minHeap;

        // Add all points to min heap
        for (auto& point : points) {
            int x = point[0];
            int y = point[1];

            int dist = (x * x) + (y * y);

            minHeap.push({dist, x, y});
        }

        vector<vector<int>> res;

        // Get k closest points
        while (k > 0) {
            auto [dist, x, y] = minHeap.top();
            minHeap.pop();

            res.push_back({x, y});
            k--;
        }

        return res;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}