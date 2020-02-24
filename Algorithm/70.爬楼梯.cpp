#include "headerfile.h"

class Solution {
public:
    int climbStairsFab(int n) {
        int res = 0;
        int a = 1, b = 2;
        for (int i = 3; i <= n; i++)
        {
            res = a + b;
            a = b;
            b = res;
        }
        return n <= 2 ? n : res;
    }

    int climb(int start, int n, int* memo) {
        if (start == n)
            return 1;
        if (start > n)
            return 0;
        if (memo[start])
            return memo[start];
        memo[start] = climb(start + 1, n, memo) + climb(start + 2, n, memo);
        return memo[start];
    }
    int climbStairs(int n) {
        int* memo = new int[n + 1];
        memset(memo, 0, sizeof(int) * n);
        return climb(0, n, memo);
    }
};