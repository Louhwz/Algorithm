#include "headerfile.h"

class Solution {
public:
    //变种二分法，nums[0]提供分界信息,先往正确的界限内逼近，再在界限内往target逼近
    //判断一下target在左段还是右段
    //如果middle
    //数轴法想象target位置
    //==target 记录middle
    //==bound说明middle==0 left=0,righ=1
    int search(vector<int> nums, int target) {
        int sSize = nums.size();
        if (sSize == 0)
            return -1;
        int bound = nums[0], left = 0, right = sSize, middle;
        bool leftPart = target >= bound ? true : false;
        while (left < right) {
            middle = (left + right) / 2;
            int k = nums[middle];
            if (k == target) {
                left = middle;
                break;
            }
            else if (target < k) {
                if (k >= bound) {
                    if (leftPart) {
                        right = middle;
                    }
                    else {
                        left = middle + 1;
                    }
                }
                else
                    right = middle;
            }
            else {
                //k<target
                if (k >= bound) {
                    //if (!leftPart) {
                    //    left = middle + 1;
                    //}
                    //else {
                    //    right = middle;
                    //}
                    left = middle + 1;
                }
                else {
                    //{3,1} 3
                    if(!leftPart)
                        left = middle + 1;
                    else {
                        right = middle;
                    }
                }
            }

        }
        return left == sSize ? -1 : (nums[left] == target ? left : -1);
    }
};

