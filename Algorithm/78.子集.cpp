#include "headerfile.h"

class Solution {
private:
    int numInSet = 0;
    vector<vector<int> > res;
    int sSize;
public:
    void traceBack(const vector<int> nums, vector<int> path, int limit, int start) {
        if (path.size() == limit) {
            res.push_back(path);
            return;
        }
        //1 2 3
        for (int i = start; i < sSize; i++) {
            if (i + limit - path.size() > sSize)
                break;
            path.push_back(nums[i]);
            traceBack(nums, path, limit, i + 1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsRecursion(vector<int>& nums) {
        vector<int> path{};    
        sSize = nums.size();
        for (int i = 0; i <= sSize; i++)
            traceBack(nums, path, i, 0);
        return res;
    }

    //二进制+位运算，集合的每个元素都可以选或者不选
    vector<vector<int> >subsets(vector<int>& nums) {
        vector<vector<int> >res;
        for (int i = 0; i < (1 << nums.size()); i++) {
            vector<int> path{};
            for (int j = 0; j < nums.size(); j++) {
                if (((i >> j) & 1) == 1)
                    path.push_back(nums[j]);
            }
            res.push_back(path);
        }
        return res;
    }
};
int main() {
    //vector<vector<int> > res{};
    vector<int> s{ 1,2,3 };
    cout << (0 >> 1);
    //cout << res.size();
}