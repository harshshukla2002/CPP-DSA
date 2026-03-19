#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> mp;
    mp["tv"] = 100;
    mp["laptop"] = 50;

    mp.insert({"watch", 50});
    mp.emplace("watch", 50);
    mp.count("laptop"); // return count of all keys in map which has laptop
    mp.erase("tv");
    mp.find("laptop"); // return element or end

    for (auto p : mp)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}