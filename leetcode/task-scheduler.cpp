#include <deque>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count frequency of each task
        unordered_map<char, int> freq;

        for (char task : tasks) {
            freq[task]++;
        }

        // Max heap: highest frequency on top
        priority_queue<int> maxHeap;

        for (auto& [task, count] : freq) {
            maxHeap.push(count);
        }

        // Queue: {remaining count, time when task becomes available}
        queue<pair<int, int>> q;

        int time = 0;

        while (!maxHeap.empty() || !q.empty()) {
            time++;

            // If a task is available, execute the most frequent one
            if (!maxHeap.empty()) {
                int cnt = maxHeap.top();
                maxHeap.pop();

                cnt--;

                if (cnt > 0) {
                    q.push({cnt, time + n});
                }
            }

            // Move tasks whose cooldown is finished back to heap
            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}