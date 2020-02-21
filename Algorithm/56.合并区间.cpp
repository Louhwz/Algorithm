#include "headerfile.h"
bool cmp(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}
class Solution {
public :
    //1 3  5 8   2 6 
    //1 8 
    //1  10  2  3
    //1 10   2 11
    //1 10   11 12

    //排序过后遍历。起点一定是越来越高的，
    //current先跟pre[1]作比较，大于的话新增区间，等于的话合并区间
    //小于的话再判断current[1]和pre[1]的关系。
    //排序的好处是不需要再从res数组的起点开始遍历，可以用index
    //记录当前遍历点
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > res;
        sort(intervals.begin(), intervals.end(),cmp);
        
		int sSize = intervals.size();
		if (sSize == 0)
			return res;
        res.push_back(intervals[0]);
        
        int index = 0;
        for (int i = 1; i < sSize; i++) {
            if (intervals[i][0] > res[index][1]) {
                res.push_back(intervals[i]);
                index++;
            }
            else if (intervals[i][0] == res[index][1]) {
                res[index][1] = intervals[i][1];
            }
            else {
                //intervals[i][0]<res[index][1]说明肯定在区间内了
                if (intervals[i][1] <= res[index][1]) {
					continue;
                }
                else {
					res[index][1] = intervals[i][1];
                }
            }
        }
		return res;
    }
};

//int main() {
//	Solution ss;
//	vector<vector<int> > s{ {1,3},{5,10},{3,6} };
//	ss.merge(s);
//}