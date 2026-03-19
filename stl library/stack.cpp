#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    stack<int> s2;

    s.push(1);
    s.pop();
    s.top(); // get top element
    s.empty();
    s2.swap(s); // move all the elements from s to s2

    return 0;
}