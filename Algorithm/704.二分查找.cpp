#include "headerfile.h"
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        int left = 0, right = nums.size() - 1, middle = 0;
        while (left <= right) {
            middle = (left + right) >> 1;
            if (nums[middle] == target)
                return middle;
            else if (nums[middle] > target) {
                right = middle - 1;
            }
            else
                left = middle + 1;
        }
        return -1;
    }
};