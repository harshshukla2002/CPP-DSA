#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int n = num1.size();
        int m = num2.size();

        vector<int> res(n + m, 0);

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int digit = (num1[i] - '0') * (num2[j] - '0');

                res[i + j] += digit;
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;
            }
        }

        reverse(res.begin(), res.end());

        int start = 0;
        while (start < res.size() && res[start] == 0)
            start++;

        string ans = "";
        while (start < res.size()) {
            ans += (res[start] + '0');
            start++;
        }

        return ans;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}