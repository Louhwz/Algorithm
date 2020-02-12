#include "headerfile.h"

class Solution {
public:
    //���ֶ��ַ���nums[0]�ṩ�ֽ���Ϣ,������ȷ�Ľ����ڱƽ������ڽ�������target�ƽ�
    //�ж�һ��target����λ����Ҷ�
    //���middle
    //���ᷨ����targetλ��
    //==target ��¼middle
    //==bound˵��middle==0 left=0,righ=1
    int search(vector<int> nums, int target) {
        int sSize = nums.size();
        if (sSize == 0)
            return -1;
        int bound = nums[0], left = 0, right = sSize, middle;
        bool leftPart = target >= bound ? true : false;
        while (left < right) {
            middle = (left + right) / 2;
            int k = nums[middle];
            if (k == target) {
                left = middle;
                break;
            }
            else if (target < k) {
                if (k >= bound) {
                    if (leftPart) {
                        right = middle;
                    }
                    else {
                        left = middle + 1;
                    }
                }
                else
                    right = middle;
            }
            else {
                //k<target
                if (k >= bound) {
                    //if (!leftPart) {
                    //    left = middle + 1;
                    //}
                    //else {
                    //    right = middle;
                    //}
                    left = middle + 1;
                }
                else {
                    //{3,1} 3
                    if(!leftPart)
                        left = middle + 1;
                    else {
                        right = middle;
                    }
                }
            }

        }
        return left == sSize ? -1 : (nums[left] == target ? left : -1);
    }
};

