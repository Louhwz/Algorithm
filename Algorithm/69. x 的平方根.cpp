#include "headerfile.h"

class Solution {
public:
    //int mySqrt(int x) {
    //    int right = x / 2 + 1;
    //    int left = 0;
    //    int middle;
    //    //2 
    //    //left = 0    right=2
    //    //middle=1  temp=1 left=1
    //    //middle=1
    //    while (left < right) {
    //        middle = (left + right) >> 1;
    //        long long temp;
    //        temp = (long long)middle * middle;
    //        if (temp > INT_MAX)
    //            right = middle;
    //        else {
    //            if (temp < x) {
    //                left = middle + 1;
    //            }
    //            else if (temp > x) {
    //                int k = middle - 1;
    //                if (k * k <= x)
    //                    return k;
    //                
    //                else
    //                    right = middle;
    //            }
    //            else {
    //                //temp == x
    //                return middle;
    //            }
    //        }

    //    }
    //    return left;
    //}

    //右中位数是关键
    int mySqrtAmazingSolution(int x) {
        int left = 0, right = x / 2 + 1;
        int middle;
        while (left < right) {
            middle = (left + right + 1) >> 1;
            long long mul = (long long)middle * middle;
            if (mul == x) {
                return middle;
            }
            else if (mul > x) {
                right = middle - 1;
            }
            else if (mul < x) {
                left = middle;
            }
        }
        return left;
    }
    //1 3    2
    int mySqrt(int x) {
        long left = 0;
        long right = x / 2;

        while (left <= right) {
            long mid = left + (right - left) / 2;
            long sqr = mid * mid; // 该值为 mid ^ 2，如果 mid 使用 int，在 x=2147395599 时, 则 mid * mid 会先越界，再被转型成 long
            long nextSqr = (mid + 1) * (mid + 1); // 该值为（mid + 1）^ 2，

            if (sqr <= x && nextSqr > x) {
                return (int)mid;
            }
            else if (sqr < x) {
                left = mid + 1;
            }
            else if (sqr > x) {
                right = mid - 1;
            }
        }
        return x;

    
    }
};

//int main() {
//    cout << Solution().mySqrt(8)<<endl;
//    cout << Solution().mySqrt(0)<<endl;
//    cout << Solution().mySqrt(1)<<endl;
//    cout << Solution().mySqrt(2)<<endl;
//    cout << Solution().mySqrt(3)<<endl;
//}