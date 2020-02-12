#include "headerfile.h"
class Solution {
public:
    
    string stringAdd(string num1, string num2) {
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

    string num1MultiplySingle(string num1, char s, int numZero) {
        string res = "";
        int jinwei = 0;
        //22 * 5
        //res=0 jinwei=1
        //10 jinwei=1 999*99 四位数×三位数 1000*100=100000 六位 最大五位数
        for (int i = num1.size() - 1; i >= 0; i--) {
            int k = (num1[i]-'0') * (s-'0') ;
            k += jinwei;
            res = to_string(k % 10) + res;
            jinwei = k / 10;
        }
        if (jinwei != 0)
            res = to_string(jinwei) + res;
        for (int i = 0; i < numZero; i++) {
            res = res + "0";
        }
        return res;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        string res = "";
        int s1Size = num1.size(), s2Size = num2.size();
        for (int n2 = s2Size - 1; n2 >= 0; n2--) {
            //s1*num2[n2]
            string temp = num1MultiplySingle(num1, num2[n2], s2Size - 1 - n2);
            res = stringAdd(res, temp);
            //temp.push_back()

        }

        return res;
    }
};

