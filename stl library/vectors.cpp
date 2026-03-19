#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 3, 4};

    arr.push_back(5);    // insert element at end
    arr.emplace_back(5); // insert element at end
    arr.pop_back();      // insert element at end

    cout << "Size: " << arr.size() << endl;         // get size
    cout << "Capacity: " << arr.capacity() << endl; // get capacity
    cout << "Front: " << arr.front() << endl;       // get front element
    cout << "Back: " << arr.back() << endl;         // get back element

    arr.at(2); // get element from index

    arr.erase(arr.begin() + 1);       // delete element from particular index
    arr.insert(arr.begin() + 1, 100); // insert element from particular index
    arr.clear();                      // clear array elements
    arr.empty();                      // returns if array is empty or not

    // loop in
    for (int val : arr)
    {
        cout << val << endl;
    }

    // reverse iteration
    vector<int>::reverse_iterator it;
    for (it = arr.rbegin(); it != arr.rend(); it++)
    {
        cout << *(it) << endl;
    }

    return 0;
}