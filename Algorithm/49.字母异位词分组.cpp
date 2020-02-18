#include "headerfile.h"

class Solution {
private:
    vector<vector<string> > res;

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int > um;
        int sSize = strs.size();
        int index = 0;  //索引数组的下标
        for (auto s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            if (um.count(temp)) {
                res[um[temp]].push_back(s);
            }
            else {
                res.push_back(vector<string>{s});
                um[temp] = index;
                index++;
            }
        }
        return res;
    }
};