//19121697926
//用KMP算法实现模式字符串匹配
#include "headerfile.h"

class Solution {
private:
    int** dp;
public:
    void constructKMP(string needle) {
        if (needle.size() <= 0)
            return;
        dp = new int*[needle.size()];
        if (dp == NULL)
            return;
        for (int i = 0; i < needle.size(); i++) {
            dp[i] = new int[256];
            if (dp == NULL)
                return;
            memset(dp[i], 0, 256 * sizeof(int));
        }
        int X = 0;
        dp[0][needle[0] - 0] = 1;
        
        for (int i = 1; i < needle.size();i++) {
            for (int j = 0; j < 256; j++) {
                dp[i][j] = dp[X][j];
            }
            dp[i][needle[i] - 0] = i + 1;
            //ababc
            //dp[0][a]=1
            //dp[1][a]=dp[0][a]=1   dp[1][b]=2    X=dp[0][b]=0
            //dp[2][a]=3    X=dp[0][a]=1
            //dp[3][b]=4    X=dp[1][b]=2
            //dp[4][c]=5    X=dp[2][c]=0
            //0(a)1(b)2(c)3
            X = dp[X][needle[i] - 0];
        }
    }
    int strStr(string haystack, string needle) {
        if (needle == "")
            return 0;
        constructKMP(needle);
        int n = haystack.size(), m = needle.size();
        int j = 0;
        for (int i = 0; i < n; i++) {            
            j = dp[j][haystack[i] - 0];
            if (j == m) {
           
                return i - m + 1;
            }
        }
 
        return -1;
    }
};
