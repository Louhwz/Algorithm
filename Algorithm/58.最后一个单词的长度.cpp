#include "headerfile.h"

class Solution {
public:
    //0
    int lengthOfLastWord(string s) {
        int lastOfSpace = s.find_last_of(' ');
        int lastNotOfSpace = s.find_last_not_of(' ');
        //È«ÊÇ¿Õ¸ñ
        if (lastNotOfSpace == -1)
            return 0;
        if (lastOfSpace == s.size() - 1) {
            lastOfSpace = s.find_last_of(' ', lastNotOfSpace);
        }
        //hello world
        //hello world[][][]
        return lastNotOfSpace - lastOfSpace;
    }
};
//int main() {
//    string s = "hello world    ";
//    int lastNotOfSpace = s.find_last_of(' ', 11);
//    cout << lastNotOfSpace;
//
//}