#include "headerfile.h"

//好优美的c代码，好聪明的章苏尧
unsigned int countBits(unsigned long long n) {
    //your code here
    unsigned int counter = 0;
    while (n != 0) {
        if (n % 2) {
            counter++;
        }
        n = n >> 1;
    }
    return counter;
}