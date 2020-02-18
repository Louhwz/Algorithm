#include "headerfile.h"

class Solution {
private:
    vector<vector<int> > res;
    int sSize = 0;
    vector<int> nums;
public:
    //ªÿÀ›À„∑®
    void trackBack(vector<int> track,bool* used) {
        if (track.size() == sSize) {
            res.push_back(track);
            return;
        }
        //1 2 3 4 
        for (int i = 0; i < sSize; i++) {
            if (used[i])
                continue;
            track.push_back(nums[i]);
            used[i] = true;
            trackBack(track, used);
            used[i] = false;
            track.pop_back();
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        sSize = nums.size();
        this->nums.assign(nums.begin(), nums.end());
        vector<int> track;
        bool* used = new bool[sSize];
        memset(used, 0, sSize);
        trackBack(track, used);
        return res;
    }
};