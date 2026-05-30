#include <iostream>
using namespace std;

class DisjointSetUnion {
   public:
    int n;
    vector<int> parent, rank;

    DisjointSetUnion(int n) {
        this->n = n;

        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    void unionByRank(int a, int b) {
        int parentA = find(a);
        int parentB = find(b);

        if (parentA == parentB) return;

        if (rank[parentA] == rank[parentB]) {
            parent[parentB] = parentA;
            rank[parentA]++;
        } else if (rank[parentA] > rank[parentB]) {
            parent[parentB] = parentA;
        } else {
            parent[parentA] = parentB;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}