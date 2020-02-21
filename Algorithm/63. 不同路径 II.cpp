#include "headerfile.h"
typedef long long ll;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0)
            return 0;
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<ll> > dp(n, vector<ll>(m, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0) {
                    if (j > 0 && dp[i][j - 1] == 0)
                        dp[i][j] = 0;
                    else
                        dp[i][j] = obstacleGrid[i][j] ? 0 : 1;
                }
                else if (j == 0) {
                    if (i > 0 && dp[i - 1][j] == 0)
                        dp[i][j] = 0;
                    else {
                        
                        dp[i][j] = obstacleGrid[i][j] ? 0 : 1;
                    }
                }
                else
                {
                    dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};