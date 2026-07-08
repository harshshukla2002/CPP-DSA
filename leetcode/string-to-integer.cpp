#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        long long result = 0;

        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // 3. Skip leading zeros
        while (i < n && s[i] == '0') {
            i++;
        }

        // 4. Read digits
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // 5. Handle overflow
            if (sign == 1 && result > INT_MAX) {
                return INT_MAX;
            }

            if (sign == -1 && -result < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return sign * result;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}