#include "headerfile.h"

class Solution {
public:
    //hash[0][x] �������ң��������£��ڼ����Ź���
    //hash[1][x] ����
    //hash[2][x] ����
    bool isValidSudoku(vector<vector<char>>& board) {
        int hash[3][9][10] = { 0 };
        
        bool res = true;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.')
                    continue;
                else {
                    int k = c - '0' + 0;
                    int position = i / 3 * 3 + j / 3;
                    if (hash[0][position][k] || hash[1][i][k] || hash[2][j][k])
                        return false;
                    hash[0][position][k] = 1;
                    hash[1][i][k] = 1;
                    hash[2][j][k] = 1;
                }
            }
        }

        return res;
    }
};