#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int firstChar(string str) {
    unordered_map<char, int> map;
    queue<int> q;

    for (int i = 0; i < str.size(); i++) {
        if (map.find(str[i]) == map.end()) {
            q.push(i);
        }

        map[str[i]]++;

        while (q.size() > 0 && map[str[q.front()]] > 1) {
            q.pop();
        }
    }

    return q.empty() ? -1 : q.front();
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}