#include "headerfile.h"

class Solution {
private:
    vector<vector<int> > res;
    vector<int> nums;
    int sSize = 0;
public:
    //1 1 1 2
    void trackBack(vector<int> track,bool *used) {
        if (track.size() == sSize) {
            res.push_back(track);
            return;
        }
        for (int i = 0; i < sSize; i++) {
            //确保同一个父节点下没有相同值的路径
            //!used[i]     i=next[i]
            //used[i]  nums[i]==nums[i-1]    i++ 然后也是i=next[i]
            //         nums[i]!=nums[i-1]    i=next[i]
            //1 1 2
            if (!used[i]) {               
                if (i > 0 && nums[i] == nums[i - 1] && !used[i-1]) {
                    continue;
                }
                track.push_back(nums[i]);
                used[i] = true;
                trackBack(track, used);
                track.pop_back();
                used[i] = false;
            }
        }

    }
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        sSize = nums.size();
        this->nums.assign(nums.begin(), nums.end());
        sort(this->nums.begin(), this->nums.end());
        vector<int> track;
        bool* used = new bool[sSize];
        memset(used, 0, sSize);

        trackBack(track, used);
        return res;
    }
};

