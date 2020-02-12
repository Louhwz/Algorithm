#include "headerfile.h"

class Solution {
public:

    //int divide(int dividend, int divisor) {
    //    int result = 0;
    //    if (divisor == 1)
    //        return dividend;
    //    if (divisor == -1) {
    //        if (dividend == INT_MIN)
    //            return INT_MAX;
    //        else
    //            return -dividend;
    //    }
    //               
    //    bool resultIsNegative = (dividend ^ divisor) & 0x80000000;
    //    if (dividend < 0)
    //        dividend = -dividend;
    //    if (divisor < 0)
    //        divisor = -divisor;
    //    if (dividend < divisor)
    //        return 0;
    //    //int kDivisor = divisor, preDivisor = divisor, preResult = result;
    //    //result = 1;
    //    ////6 2
    //    ////12 4
    //    ////kDivisor不能加溢出 & 保出一个值，以二分法最接近dividend的divisor的倍数
    //    //while (kDivisor < dividend) {
    //    //    preDivisor = kDivisor;
    //    //    preResult = result;
    //    //    kDivisor += kDivisor;
    //    //    if (kDivisor <= 0)
    //    //        break;
    //    //    result += result;
    //    //}

    //    int kDivisor = divisor;
    //    result = 1;
    //    while (dividend - kDivisor - kDivisor > 0) {
    //        kDivisor += kDivisor;
    //        result += result;
    //    }
    //    while (dividend - kDivisor >= divisor) {
    //        kDivisor += divisor;
    //        result += 1;
    //    }
    //    return resultIsNegative ? -result : result;


    //    //while (1) {
    //    //    if (dividend - preDivisor < divisor)
    //    //        break;
    //    //    preDivisor += divisor;
    //    //    preResult += 1;
    //    //}

    //    //return resultIsNegative ? -preResult : preResult;

    //}

    int divide(int dividend, int divisor) {    
        bool resultIsNegative = (dividend ^ divisor) & 0x80000000;
        if (dividend > 0)
            dividend = -dividend;
        if (divisor > 0)
            divisor = -divisor;
        int lbResult = divisor;

    }
};

//int main() {
//    Solution ss;
//
//    cout << ss.divide(2147483647, 2);
//}