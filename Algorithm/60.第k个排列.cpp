#include "headerfile.h"

class Solution {
private:
    int num = 0;
    vector<int> path;
    vector<int> res;
    int n, k;
public:

    void trackBack(bool *visited) {
        if (path.size() == this->n) {
            num++;
            if (num == this->k) {
                res = path;
            }
            return;
        }
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;
            path.push_back(i + 1);
            visited[i] = true;
            trackBack(visited);
            if (num == this->k)
                return;
            visited[i] = false;
            path.pop_back();
        }
        
    }
    string getPermutationMyself(int n, int k) {
        //vector<int> intervals(9);
        //int res = 1;
        //for (int i = 2; i <= 10; i++) {
        //    intervals.push_back(res);
        //    res *= i;
        //}
        this->n = n;
        this->k = k;
        bool* visited = new bool[n];
        memset(visited, 0, n);
        trackBack(visited);
        string resS = "";
        for (int i = 0; i < this->res.size(); i++) {
            resS += to_string(res[i]);
        }
        return resS;


    }




    string getPermutationONtan(int n, int k) {
        string s = string("123456789").substr(0, n);
        for (int i = 1; i < k; i++)next_permutation(s.begin(), s.end());
        return s;
    }

    //直接得出排列的结果，也不需要中间数组
    //1 2 3 4, 1 2 4 3, 1 3 2 4, 1 3 4 2, 1 4 2 3, 1 4 3 2
    //2 1 3 4, 2 1 4 3, 2 3 1 4, 2 3 4 1, 2 4 1 3, 2 4 3 1
    //3 1 2 4, 3 1 4 2, 3 2 1 4

    //4 9  
    //k: 当前序列的第几个排列
    //bound: 当前序列去掉首部的数后的最大排列数s
    string getPermutation(int n, int k) {
        int nn = n;
        string s = string("123456789").substr(0, n);
        string res(n, ' ');
        int bound = 1;
        for (int i = (--n); i > 0; i--) {
            bound *= i;
        }
        int index = 0;
        k--;
        while (index < nn)
        {
            int seq = k / bound;
            res[index++] = s[seq];
            s.erase(seq, 1);
            k = k % bound;

            if (n == 0)
                break;
            bound /= (n--);
        }
        return res;
    }
};

//int main() {
//    Solution ss;
//    cout<<ss.getPermutation(4, 9);
//}