#include <deque>
#include <iostream>
#include <vector>
using namespace std;

vector<int> getMaximum(vector<int>& arr, int k) {
    vector<int> res;
    deque<int> dq;

    for (int i = 0; i < k; i++) {
        while (dq.size() > 0 && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for (int i = k; i < arr.size(); i++) {
        res.push_back(arr[dq.front()]);

        while (dq.size() > 0 && dq.front() <= i - k) dq.pop_front();

        while (dq.size() > 0 && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    res.push_back(arr[dq.front()]);

    return res;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}