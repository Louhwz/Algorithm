#include "headerfile.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int** dp = new int* [m];
        for (int i = 0; i < m; i++) {
            dp[i] = new int[n];
            memset(dp[i], 0, n * 4);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    dp[i][j] = 1;
                }
                else if (j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        int res = dp[m - 1][n - 1];
        for (int i = 0; i < m; i++)
            delete[]dp[i];
        delete[]dp;
        return res;
    }
};

//int main() {
//    cout<< Solution().uniquePaths(3, 2);
//}