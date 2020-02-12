#include "headerfile.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int sSize = nums.size();
        vector<int> result;
        if (sSize == 0)
            return vector<int>{ -1,-1 };
        int left = 0, right = sSize, middle;
        while (left < right) {
            middle = (left + right) / 2;
            if (nums[middle] == target) {
                if (middle - 1 >= 0 && nums[middle - 1] == target) {
                    right = middle;
                }
                else {
                    left = middle;
                    break;
                }
            }
            else if (target > nums[middle]) {
                left = middle + 1;
            }
            else {
                //target < nums[middle]
                right = middle;
            }
        }
        if (left==sSize||nums[left] != target)
            return vector<int>{-1, -1};
        result.push_back(left);
        right = sSize;
        while (left < right) {
            middle = (left + right) / 2;
            if (nums[middle] == target) {
                if (middle + 1 < sSize && nums[middle + 1] == target) {
                    left = middle;
                }
                else {
                    left = middle;
                    break;
                }
            }
            else if (target > nums[middle]) {
                left = middle + 1;
            }
            else {
                right = middle;
            }
        }
        result.push_back(left);
        return result;

    }
};
