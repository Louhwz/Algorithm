#include "headerfile.h"

class Solution {
public:
    string simplifyPath(string path) {
        deque<char> deq(0);
        int sSize = path.size();
        if (sSize == 0)
            return "";
        for (int i = 0; i < sSize; i++) {
            char cur = path[i];

            if (cur == '/') {
                if (!deq.empty() && deq.back() == '/')
                    continue;
                else
                    deq.push_back(cur);
            }
            else if (cur == '.') {
                //默认.肯定不是倒数第一个元素，因为还有引号，所以直接访问
                if (i + 1 < sSize && path[i + 1] == '.') {
                    if (i + 2 < sSize && path[i + 2] == '.') {
                        deq.push_back('.');
                        deq.push_back('.');
                        deq.push_back('.');
                        i += 2;
                    }
                    else {
                        if ((i + 2 < sSize && path[i + 2] == '/') || (i + 2 == sSize)) {
                            //pop
                            if (deq.size() > 1)
                                deq.pop_back();
                            while (deq.back() != '/')
                                deq.pop_back();
                            i++;
                            continue;
                        }
                        else {
                            deq.push_back('.');
                            deq.push_back('.');
                            i++;
                        }
                    }
                }
                else if (i + 1 < sSize && path[i + 1] != '/') {
                    deq.push_back('.');
                }
            }
            else
                deq.push_back(cur);
        }
        //对/的后处理，注意与根节点区分
        string res = "";
        for (int i = 0; i < deq.size(); i++) {
            if (i == deq.size() - 1 && deq.at(i) == '/' && i>0)
                continue;
            res += deq.at(i);
        }
        return res;
    }
};

