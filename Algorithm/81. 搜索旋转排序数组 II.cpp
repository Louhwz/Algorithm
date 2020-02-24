#include "headerfile.h"

//可能存在重复
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        int middle;
        while (left <= right) {
            middle = (left + right) >> 1;
            if (nums[middle] == target)return true;
            if (nums[left] == nums[middle]) {
                left++;
            }
            else if (nums[left] < nums[middle]) {
                if (target < nums[middle] && target >= nums[left]) {
                    right = middle - 1;
                }
                else
                    left = middle + 1;
            }
            else if (nums[left] > nums[middle]) {
                if (target > nums[middle] && target <= nums[right]) {
                    left = middle + 1;
                }
                else
                {
                    right = middle - 1;
                }
            }

        }
        return false;
    }
};

int main() {
    vector<int> s{ 1,3,1,1 };

    cout<<Solution().search(s, 3);
}