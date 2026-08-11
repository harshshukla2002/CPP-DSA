#include <deque>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<long long> printFirstNegativeInteger(vector<long long>& A, int N, int K) {
        vector<long long> ans;
        deque<int> dq;

        for (int i = 0; i < N; i++) {
            // If current element is negative, store its index
            if (A[i] < 0) {
                dq.push_back(i);
            }

            // Remove elements which are outside the current window
            if (!dq.empty() && dq.front() <= i - K) {
                dq.pop_front();
            }

            // Window is complete
            if (i >= K - 1) {
                if (!dq.empty()) {
                    ans.push_back(A[dq.front()]);
                } else {
                    ans.push_back(0);
                }
            }
        }

        return ans;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}