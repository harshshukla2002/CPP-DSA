#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        string res = "";
        int increment = 2 * (numRows - 1);

        for (int r = 0; r < numRows; r++) {
            for (int i = r; i < s.size(); i += increment) {
                // Vertical character
                res += s[i];

                // Diagonal character (only for middle rows)
                int diagonal = i + increment - 2 * r;
                if (r > 0 && r < numRows - 1 && diagonal < s.size()) {
                    res += s[diagonal];
                }
            }
        }

        return res;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}