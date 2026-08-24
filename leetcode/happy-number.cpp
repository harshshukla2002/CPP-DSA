#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    int sumOfSquares(int n) {
        int output = 0;

        while (n) {
            int digit = n % 10;
            output += digit * digit;
            n /= 10;
        }

        return output;
    }

    bool isHappy(int n) {
        unordered_set<int> visit;

        while (visit.find(n) == visit.end()) {
            visit.insert(n);

            n = sumOfSquares(n);

            if (n == 1) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}