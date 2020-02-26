#include "headerfile.h"

class Solution {
private:
    vector<vector<int> > res;
    int n;
    int k;
public:
    void traceBack(vector<int> path,int start) {
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }

        for (int i = start; i <= n; i++) {
            if (i + (k - path.size()) -1 > n)
                break;
            path.push_back(i);
            traceBack(path, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        vector<int> path;
        traceBack(path, 1);
        return res;
    }
};