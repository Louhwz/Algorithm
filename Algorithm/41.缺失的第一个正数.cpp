#include "headerfile.h"
//5 3 2 1  
//你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
//max是后路，一般取min，除非min为0
//确保一个数占到自己的坑位后能稳稳的占住那个位置，把重复的数安排到了后半段，妙啊，秒啊
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sSize = nums.size();
        for (int i = 0; i < sSize; i++) {
            while (nums[i] != (i + 1)) {
                int k = nums[i];
                if (k <= 0 || k > sSize || nums[i] == nums[nums[i] - 1])
                    break;

                int index = nums[i] - 1;
                int temp = nums[i];
                nums[i] = nums[index];
                nums[index] = temp;

            }
        }
        for (int i = 0; i < sSize; i++) {
            if (nums[i] != (i + 1))
                return i + 1;
        }
        return sSize + 1;

    }
};
//4 3 3 2 1
//2 3 3 4 1
//3 2 3 4 1
//now i=1
//now i=2
//now i=3
//now i=4
//
//int main() {
//    Solution ss;
//    vector<int> s{ 1,2,3,3,4 };
//    ss.firstMissingPositive(s);
//}