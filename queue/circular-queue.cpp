#include <iostream>
#include <vector>
using namespace std;

class CircularQueue
{
    int *arr;
    int currSize, cap;
    int f, r;

public:
    CircularQueue(int size)
    {
        cap = size;
        arr = new int[cap];
        f = 0;
        r = -1;
    }

    void push(int val)
    {
        if (currSize == cap)
            return;

        r = (r + 1) % cap;
        arr[r] = val;
        currSize++;
    }

    void pop()
    {
        if (empty())
            return;

        f = (f + 1) % cap;
        currSize--;
    }

    int front()
    {
        if (empty())
            return;

        return arr[f];
    }

    bool empty()
    {
        return currSize == 0;
    }
};

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}