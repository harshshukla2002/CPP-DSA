#include <iostream>
// import vector here
#include <vector>
using namespace std;

int main()
{
    // syntax
    vector<int> num = {1, 2, 3, 4, 5, 6};

    // use diffrent type of loop for this
    for (int i : num)
    {
        cout << i << endl;
    }

    /*
    functions in vector =>
      1. to get size -> num.size();
      2. push element at last => num.push_back(el);
      3. remove element at last => num.pop_back();
      4. get element at front => num.front();
      5. get element at last => num.back();
      6. get element at index => num.at(index)
    */

    return 0;
}