#include "headerfile.h"

//ËÍ·Ö
class Solution {
private:
    int n, m;
public:
    int calculate(vector<vector<int> >& grid,int i, int j) {
        
        if (i == n || j == m)  return INT_MAX;
        if (i == n - 1 && j == m - 1)  return grid[i][j];
        return grid[i][j] + min(calculate(grid, i + 1, j), calculate(grid, i, j + 1));
    }
    int minPathSumRecursion(vector<vector<int>>& grid) {
        this->n = grid.size(), this->m = grid[0].size();
        return calculate(grid, 0, 0);
    }


    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int> > dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!i && !j) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                if (i == 0)
                    dp[i][j] = grid[i][j] + dp[i][j - 1];
                else if (j == 0)
                    dp[i][j] = grid[i][j] + dp[i - 1][j];
                else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};

//int main() {
//    vector<vector<int> > s{ {1, 3, 1}, { 1,5,1 }, { 4,2,1 }};
//    Solution().minPathSumRecursion(s);
//}