#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    queue<int> q2;

    q.push(1);
    q.pop();
    q.front(); // get top element
    q.empty();
    q2.swap(q); // move all the elements from s to s2

    return 0;
}