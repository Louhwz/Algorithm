#include "headerfile.h"

class Solution {
public:
    //1 3 2 4 --> 1 3 4 2
    //2 4 3 1 --> 3 1 2 4
    //4 3 2 1 --> 1 2 3 4
    //4 1 3 2 --> 4 2 1 3
    //9 1 2 5 6 --> 9 1 2 6 5 --> 9 1 5 2 6  --> 9 1 5 6 2 --> 9 1 6 2 5 --> 9 1 6 5 2
    //5 9 6 2 1 --> 6 1 2 5 9
    void nextPermutation(vector<int>& nums) {
        int numsSize = nums.size();
        if (numsSize == 0 || numsSize == 1)
            return;
        int k = numsSize - 1;
        while (k > 0) {
            if (nums[k] > nums[k - 1])
                break;
            k--;
        }
        //5 6 4 3

        if (k == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        k--;
        int l = k + 1;
        for (int i = k + 1; i < numsSize; i++) {
            if (nums[i] > nums[k])
                l = i;
        }
        swap(nums[l], nums[k]);
        reverse(nums.begin() + k + 1, nums.end());

    }
};
