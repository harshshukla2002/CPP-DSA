#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> res(n, 0);
        stack<pair<int, int>> st;  // {temperature, index}

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > st.top().first) {
                int temp = st.top().first;
                int index = st.top().second;
                st.pop();

                res[index] = i - index;
            }

            st.push({temperatures[i], i});
        }

        return res;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}