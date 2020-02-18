#include "headerfile.h"

class Solution {
public:
    //���ֵݹ�ṹ�������ڴӵײ�����չ��
    double fastPow(double x, long long n) {
        if (n == 0)
            return 1;
        double half = fastPow(x, n / 2);

        //ż��
        if (n % 2 == 0) {
            return half * half;
        }
        //����
        else {
            return half * half * x;
        }
    }

    //1����ֵ��Χ    2������
    //���֣��������㷨��
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