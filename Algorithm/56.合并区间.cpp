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

    //���������������һ����Խ��Խ�ߵģ�
    //current�ȸ�pre[1]���Ƚϣ����ڵĻ��������䣬���ڵĻ��ϲ�����
    //С�ڵĻ����ж�current[1]��pre[1]�Ĺ�ϵ��
    //����ĺô��ǲ���Ҫ�ٴ�res�������㿪ʼ������������index
    //��¼��ǰ������
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
                //intervals[i][0]<res[index][1]˵���϶�����������
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