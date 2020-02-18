#include "headerfile.h"

class Solution {
public:
    //2,3,1,1,4
    //2,0,0,3,1,1,4
    //2 0 1
    //O(n^2)
    bool canJumpON2(vector<int>& nums) {
        int sSize = nums.size();
        if (sSize == 0 || sSize == 1)
            return true;
        bool* jumpJump = new bool[sSize];
        memset(jumpJump, 0, sSize);
        int index = sSize - 2;
        while (index >= 0) {
            int ceiling = index + nums[index];
            if (ceiling >= sSize - 1)
                jumpJump[index] = true;
            
            for (int i = index; i <= min(sSize - 2, ceiling) && !jumpJump[index]; i++) {
                if (jumpJump[i]) {
                    jumpJump[index] = true;
                    break;
                }
                //jumpJump[index] = jumpJump[index] || jumpJump[i];
            }


            index--;
        }
        return jumpJump[0];
    }


    bool canJump(vector<int>& nums) {
        int maxRange = 0;
        for (int i = 0; i < nums.size() && maxRange < nums.size() - 1; i++) {
            if (i > maxRange)
                return false;
            maxRange = max(maxRange, i + nums[i]);
        }
        return true;
    }
};