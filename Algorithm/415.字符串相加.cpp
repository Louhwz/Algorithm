#include "headerfile.h"

//一个string字符串被当作实数的时候 权重最小的位置索引位置确是最大的
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int carry = 0, l1 = num1.size() - 1, l2 = num2.size() - 1;
        while (l1 >= 0 || l2 >= 0) {
            int n1 = l1 >= 0 ? num1[l1] - '0' : 0;
            int n2 = l2 >= 0 ? num2[l2] - '0' : 0;
            int temp = n1 + n2 + carry;
            res = to_string(temp % 10) + res;
            carry = temp / 10;
            l1--, l2--;
        }
        if (carry == 1)
            res = "1" + res;
        return res;
    }
};

int main() {
    string res = "123", k = "222";
    res += k + "0";
    cout << res;

}
