#include "headerfile.h"

//��������c���룬�ô���������Ң
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