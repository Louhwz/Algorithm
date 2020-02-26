#include "headerfile.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int index0 = 0, index2 = nums.size() - 1;
        if (index2 == -1)
            return;
        for (int it = 0; it < nums.size(); it++) {
            switch (nums[it]) {
            case 0:swap(nums[it],nums[index0++]); break;
            case 1:break;
            case 2:               
                while (index2 >= it && nums[it] == 2)
                    swap(nums[it], nums[index2--]);
                if (nums[it] == 0) {
                    swap(nums[it], nums[index0++]);
                    
                }
                break;               
            }
        }
    }
};

//int main() {
//    vector<int> s{ 2,0,2,1,1,0 };
//    Solution().sortColors(s);
//}