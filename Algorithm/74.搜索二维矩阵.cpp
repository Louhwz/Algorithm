#include "headerfile.h"
//1 3 5
//0 1 2 
//target=1
//left=0 right=3 middle=1
//target=6
//
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowNum = matrix.size();
        if (rowNum == 0)
            return false;
        if (!matrix[0].size())
            return false;
        int columnNum = matrix[0].size();
        int left = 0, right = rowNum, middle;
        while (left < right) {
            middle = left + (right - left) / 2;
            int k = matrix[middle][0];
            if (k == target) {
                return true;
            }
            else if (k < target) {
                left = middle + 1;
            }
            else if (k > target) {
                right = middle;
            }
        }
        left--;
        if (left == -1)
            return false;
        int row = left;
        left = 0, right = columnNum;
        while (left < right) {
            middle = left + (right - left) / 2;
            int k = matrix[row][middle];
            if (k == target) {
                return true;
            }
            else if (k > target) {
                right = middle;
            }
            else if (k < target) {
                left = middle + 1;
            }
        }
        return left == columnNum ? false : (matrix[row][left] == target);

    }
};

int main() {
    vector<vector<int>> matrix;
    cout << matrix[0].size();
    //Solution().searchMatrix(matrix, 1);
}