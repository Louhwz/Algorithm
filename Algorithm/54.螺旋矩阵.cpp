#include "headerfile.h"

class Solution {
public:
    //边界法
    vector<int> spiralOrder(vector<vector<int>> matrix) {
        vector<int> res;
        if (matrix.empty())  return res;
        //定义上下左右边界
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while (true) {
            for (int i = left; i <= right; i++)
                res.push_back(matrix[top][i]);
            if (++top > bottom) break;

            for (int i = top; i <= bottom; i++)
                res.push_back(matrix[i][right]);
            if (--right < left)    break;

            for (int i = right; i >= left; i--)
                res.push_back(matrix[bottom][i]);
            if (--bottom < top)    break;
            
            for (int i = bottom; i >= top; i--)
                res.push_back(matrix[i][left]);
            if (++left > right)    break;
        }
        return res;
    }
};

int main() {
    Solution ss;
    ss.spiralOrder(vector<vector<int> >{ {1, 2, 3}, { 4,5,6 }, { 7,8,9 }});
}