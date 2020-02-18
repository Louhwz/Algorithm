#include "headerfile.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sSize = digits.size();

        if (digits[sSize - 1] != 9) {
            digits[sSize - 1] += 1;
            return digits;
        }
        else {
            int carry = 1;
            for (int i = sSize - 1; i >= 0 && carry !=0; i--) {
                int temp = digits[i] + carry;
                digits[i] = temp % 10;
                carry = temp / 10;
            }
            if (carry != 0)
                digits.insert(digits.begin(), 1);
            return digits;
        }

    }
};

//int main() {
//    vector<int> kk{ 1,2,3 };
//    kk.insert(kk.begin(), 0);
//    vector<int> cc{ kk };
//    for (int i = 0; i < cc.size(); i++) {
//        cout << cc[i];
//    }
//}