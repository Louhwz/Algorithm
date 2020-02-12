#include "headerfile.h"
//���ַ��ĵȺ��벻�Ⱥ���Ե
//���ڶ��ַ��Ŀ����������Ҫ���ص�ֵ
//���ػᱻ˳������λ��
class Solution {
public:
    int searchInsertWrong(vector<int>& nums, int target) {
        int sSize = nums.size();
        int left = 0, right = sSize - 1, index = -1;
        while (left < right) {
            int middle = (left + right) / 2;
            if (nums[middle] == target) {
                index = middle;
                break;
            }
            else if (nums[middle] > target) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }
        if (nums[left] == target)
            return left;
        else if (nums[left] > target)
            return left - 1;
        else
            return left + 1;
    }
    //{ 1 3 5 6 }
    //-1, 1, 2, 4, 7
    int searchInsert(vector<int>& nums, int target) {
        int sSize = nums.size();
        int left = 0, right = sSize - 1;
        while (left < right) {
            int middle = (left + right) / 2;
            if (nums[middle] == target) {
                return middle;
            }
            else if (nums[middle] > target) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }

        return left;
    }

    int searchInsertAnother(vector<int>& nums, int target) {
        int sSize = nums.size();
        int left = 0, right = sSize - 1, middle;
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] == target)
                return middle;
            else if (target > nums[middle]) {
                left = middle + 1;
            }
            else {
                //target<nums[middle]
                right = middle - 1;
            }
        }
        return left;
    }

};

