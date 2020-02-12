#include "headerfile.h"
//5 3 2 1  
//����㷨��ʱ�临�Ӷ�ӦΪO(n)������ֻ��ʹ�ó�������Ŀռ䡣
//max�Ǻ�·��һ��ȡmin������minΪ0
//ȷ��һ����ռ���Լ��Ŀ�λ�������ȵ�ռס�Ǹ�λ�ã����ظ��������ŵ��˺��Σ�����밡
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sSize = nums.size();
        for (int i = 0; i < sSize; i++) {
            while (nums[i] != (i + 1)) {
                int k = nums[i];
                if (k <= 0 || k > sSize || nums[i] == nums[nums[i] - 1])
                    break;

                int index = nums[i] - 1;
                int temp = nums[i];
                nums[i] = nums[index];
                nums[index] = temp;

            }
        }
        for (int i = 0; i < sSize; i++) {
            if (nums[i] != (i + 1))
                return i + 1;
        }
        return sSize + 1;

    }
};
//4 3 3 2 1
//2 3 3 4 1
//3 2 3 4 1
//now i=1
//now i=2
//now i=3
//now i=4
//
//int main() {
//    Solution ss;
//    vector<int> s{ 1,2,3,3,4 };
//    ss.firstMissingPositive(s);
//}