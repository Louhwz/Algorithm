#include "headerfile.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowNum = matrix.size();
        if (rowNum == 0)
            return;
        int columnNum = matrix[0].size();
        bool rowZero = false, columnZero = false;
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < columnNum; j++) {
                if (i == 0 && j == 0) {
                    if (matrix[i][j] == 0) {
                        rowZero = true, columnZero = true;   
                    }
                    continue;
                }
                if (i == 0) {
                    if (matrix[i][j] == 0) {
                        rowZero = true;
                    }
                }
                else if (j == 0) {
                    if (matrix[i][j] == 0)
                        columnZero = true;
                }
                else {
                    if (matrix[i][j] == 0) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        for (int i = 1; i < rowNum; i++) {
            if (matrix[i][0] == 0) {
                //vector快速置零的方法
                for (int j = 1; j < columnNum; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < columnNum; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < rowNum; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (rowZero) {
            for (int j = 0; j < columnNum; j++)
                matrix[0][j] = 0;
        }
        if (columnZero) {
            for (int i = 0; i < rowNum; i++)
                matrix[i][0] = 0;
        }
    }
};