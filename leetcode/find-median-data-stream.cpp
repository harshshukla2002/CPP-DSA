#include <iostream>
using namespace std;

class MedianFinder {
   private:
    // Smaller half
    priority_queue<int> maxHeap;

    // Larger half
    priority_queue<int, vector<int>, greater<int>> minHeap;

   public:
    MedianFinder() {}

    void addNum(int num) {
        // Step 1: Add to maxHeap
        maxHeap.push(num);

        // Step 2: Make sure every element in maxHeap
        // is <= every element in minHeap
        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int val = maxHeap.top();
            maxHeap.pop();

            minHeap.push(val);
        }

        // Step 3: Balance the sizes
        if (maxHeap.size() > minHeap.size() + 1) {
            int val = maxHeap.top();
            maxHeap.pop();

            minHeap.push(val);
        } else if (minHeap.size() > maxHeap.size()) {
            int val = minHeap.top();
            minHeap.pop();

            maxHeap.push(val);
        }
    }

    double findMedian() {
        // Odd number of elements
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }

        // Even number of elements
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}