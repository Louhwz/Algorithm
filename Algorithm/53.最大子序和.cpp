#include "headerfile.h"

class Solution {
public:
    int maxSubArraySpaceComplexityON(vector<int>& nums) {
        int sSize = nums.size();
        int* dp = new int[sSize];
        int result = INT_MIN;
        memset(dp, 0, sizeof(int) * sSize);
        dp[0] = nums[0];
        result = dp[0];
        //dp[i]=max(dp[i-1]+nums[i],nums[i])
        for (int i = 1; i < sSize; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }

    int maxSubArray(vector<int>& nums) {
        int sSize = nums.size();
        int result = INT_MIN;

        int sum = nums[0];
        result = sum;
        //dp[i]=max(dp[i-1]+nums[i],nums[i])
        for (int i = 1; i < sSize; i++) {
        //    dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            sum = max(sum + nums[i], nums[i]);
            result = max(result, sum);
        }
        return result;
    }
};