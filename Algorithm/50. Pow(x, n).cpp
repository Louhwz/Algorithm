#include "headerfile.h"

class Solution {
public:
    //这种递归结构很适用于从底层往上展开
    double fastPow(double x, long long n) {
        if (n == 0)
            return 1;
        double half = fastPow(x, n / 2);

        //偶数
        if (n % 2 == 0) {
            return half * half;
        }
        //奇数
        else {
            return half * half * x;
        }
    }

    //1、数值范围    2、提速
    //二分（快速幂算法）
    double myPow(double x, int n) {
        //double res = 1;
        //for (int i = 1; i <= abs(n); i++) {
        //    res *= x;
        //}
        //return n > 0 ? res : 1 / res;
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double res = fastPow(x, N);
        return res;
    }
};

//int main() {
//    Solution ss;
//    ss.myPow(2, 10);
//}