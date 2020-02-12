#include "headerfile.h"
//1 2 2 2 5 target=5
//1 1 2 5 6 7 10 target=8 
//1 1 1 3 3 5 target=8
//简洁就是美
//递归回溯的一个诀窍就是把一些 设成类的私有变量
class Solution {
private:
    vector<vector<int> > result;
    vector<int> next_pos;
public:
    //1 2 3 4 5    target = 7 or 8
    //在startNum上跳过重复的数字，其他的时候顺序遍历就好
    //两个错误：1、i遍历完一遍以后，startNum没有变 2、i应该从不重复的第一个数开始，而不是简单的自加
    void trackBack(vector<int> track, const vector<int> candidates, int shiftyTarget, int startNum,bool isOutside) {
        for (int i = startNum; i < candidates.size();) {
            if (candidates[i] == shiftyTarget) {
                track.push_back(candidates[i]);
                result.push_back(track);
                return;
            }
            else if(candidates[i]<shiftyTarget){
                //candidates[i] < shiftyTarget
                track.push_back(candidates[i]);
                if (i > 0 && candidates[i] == candidates[i - 1]) {
                    trackBack(track, candidates, shiftyTarget - candidates[i], next_pos[i], false);
                    i = next_pos[i];
                }
                else {
                    trackBack(track, candidates, shiftyTarget - candidates[i], i + 1, false);
                    i++;
                }
                track.pop_back();
            }
            else {
                //candidates[i]>shiftyTarget
                return;
            }

            if (isOutside)
                break;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int sSize = candidates.size();
        if (sSize == 0)
            return result;
        sort(candidates.begin(), candidates.end());
        vector<int> track;
        int pre = sSize;
        //next_pos[sSize - 1] = sSize;
        next_pos.push_back(sSize);
        for (int i = sSize - 2; i >= 0; i--) {
            //if (candidates[i] == candidates[i + 1])
            //    next_pos[i] = pre;
            //else {
            //    pre = i+1;
            //    next_pos[i] = pre;
            //}
            if (candidates[i] != candidates[i + 1])
                pre = i + 1;
            //next_pos[i] = pre;
            next_pos.push_back(pre);
        }
        reverse(next_pos.begin(), next_pos.end());
        int startNum = 0;
        while (startNum < sSize) {

            trackBack(track, candidates, target, startNum,true);
            //find next startNum
            startNum++;
            while (startNum < sSize && candidates[startNum] == candidates[startNum - 1])
                startNum++;
        }

        return result;
    }
};



class SolutionCopy {

private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
public:
    void DFS(int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        //1 1 1 1 1 1 target=3
        //1 1 1 3 3 5 target=8
        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
            //i>start是精髓啊，保证了第一个有重复元素的结果
            if (i > start&& candidates[i] == candidates[i - 1])
                continue;
            path.push_back(candidates[i]);
            // 元素不可重复利用，使用下一个即i+1
            DFS(i + 1, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);
        return res;
    }
};

