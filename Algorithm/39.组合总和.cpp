#include "headerfile.h"
//µÝ¹é»ØËÝ
class Solution {
private:
    vector<vector<int> > result;
public:
    //2 3 
    //3 
    void trackBack(vector<int> track, vector<int> candidates, int shiftyTarget) {   
        for (int i = 0; i < candidates.size(); i++) {
            if(track.size()!=0)
                if (candidates[i] < track.back())
                    continue;
            if (candidates[i] > shiftyTarget) {
                return;
            }
            else if (candidates[i] == shiftyTarget) {
                track.push_back(candidates[i]);
                result.push_back(track);
                return;
            }
            else {
                track.push_back(candidates[i]);
                trackBack(track, candidates, shiftyTarget - candidates[i]);
                track.pop_back();
            }           
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sSize = candidates.size();
        if (sSize == 0)
            return result;
        sort(candidates.begin(), candidates.end());
        vector<int> track;
        trackBack(track, candidates, target);
        return result;
    }
};

