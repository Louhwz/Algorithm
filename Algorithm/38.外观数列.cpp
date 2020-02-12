#include "headerfile.h"

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 2; i <= n; i++) {
            int n = res.size();
            string temp = "";
            size_t j = 0;
            while (j != string::npos) {
                size_t sec = res.find_first_not_of(res[j], j);
                int num = sec == string::npos ? n - j : sec - j;
                temp += to_string(num);
                temp += res[j];
                j = sec;
            }
            res = temp;
        }
        return res;
    }
};
