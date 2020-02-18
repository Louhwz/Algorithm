#include "headerfile.h"
class Solution {
public:
    //先转置再翻转，时间复杂度O(n^2)，空复O(1)
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (auto &row : matrix) reverse(row.begin(), row.end());
    }
};
//int main() {
//    vector<vector<int> > matrix{ {1,2,3},{4,5,6} };
//    for (auto row : matrix) {
//        cout << row[0];
//        vector<int> &temp = matrix[0];
//        reverse(temp.begin(), temp.end());
//    }
//}