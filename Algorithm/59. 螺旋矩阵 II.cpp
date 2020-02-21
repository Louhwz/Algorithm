#include "headerfile.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //vector<vector<int> > res;
        //res.resize(n);
        //for (int i = 0; i < n; i++) {
        //    res[i].resize(n);
        //}
        vector<vector<int> > res(n, vector<int>(n));
        int index = 1, target = n * n;
        int left = 0, top = 0, right = n - 1, bottom = n - 1;
        
        while (index <= target) {
            for (int i = left; i <= right; i++)
                res[top][i] = index++;
            if (++top > bottom)
                break;
            for (int i = top; i <= bottom; i++)
                res[i][right] = index++;
            if (--right < left)
                break;
            for (int i = right; i >= left; i--)
                res[bottom][i] = index++;
            if (--bottom < top)
                break;
            for (int i = bottom; i >= top; i--)
                res[i][left] = index++;
            if (++left > right)
                break;
                          
        }
        return res;

    }
};