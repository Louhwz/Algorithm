#include "headerfile.h"
//ˢ���д�㷨����
class Solution {
public:
    //��֤��������һλ�ο��ԡ����о�����Ҫdp��ֻ��Ҫ���״ֵ̬����Ӧ�û�����Ҫdp�洢״ֵ̬��
    //�С������ж��ԡ����������Ϊ���ܴ浵����Ϸ�����˾�Ҫ��ͷ��ʼ����
    //ʧ���ˣ������أ���Ϊû�취ȷ��positionλ�ʹ���λ
    //1���ҳ���һ�������ţ���¼��λ��k
    //2����k�������������������ÿһ�������Ŷ��ж����ұ�һλ�Ƿ�Ϊ
    //�����ţ�������ǣ���ô���λ���ϵĺ�������ֵ����max[����ֵ,0]+1
    //����ǣ���ô�ж϶�Ӧλ���ϵ��ַ��Ƿ�Ϊ�����ţ�����ǣ�
    //����dpֵ��������ǣ�������ϵ���������ѣ������λ�ÿ�ʼ������
    //�����µ����Ŵ�����Ϊ-1��ʾ���ɴ��ô֮�����з��ִ˴�Ϊ-1��
    //�������Ŷ��Ὣ��dpֵ��Ϊ-1��ʾ����״̬��
    //3������������ֱ����֮������
    //���أ�����dpֵ
    //((())) ((())
    //(()()) ((()))() ((())())
    // ((()))() ((())()) ���ж�����
    //һ��positionλ��һ��bombardPositionλ��
    int longestValidParenthesesFail(string s) {
        int k = -1, sSize = s.size();
        if (sSize == 0 || sSize == 1)
            return 0;
        int result = 0;
        for (int i = sSize-1; i >= 0; i--) {
            if (s[i] == '(') {
                k = i;
                break;
            }
        }
        int delivery, rightAccumulation = 0;
        if (k < 0)
            return 0;
        if (k == sSize - 1)
            delivery = -1;
        else {
            rightAccumulation = 1;
            delivery = 1;
            result = 1;
        }
        k--;

        while (k >= 0) {
            if (s[k] == ')') {
                rightAccumulation = 0;
            }
            //'('
            else{
                if (s[k + 1] == '(') {
                    int bombardPosition = k + rightAccumulation * 2 + 1;
                    rightAccumulation++;
                    if (bombardPosition>=sSize or s[bombardPosition]== '(') {
                        delivery = -1;
                    }
                    else {
                        delivery = max(delivery, 0) + 1;
                        result = max(result, delivery);
                    }
                }
                else {
                    rightAccumulation = 1;
                    delivery = max(delivery, 0) + 1;
                    result = max(result, delivery);
                }
            }
            k--;
        }

        return 2 * result;
    }

    //if(s[i-1]=='(') dp[i]=dp[i-2]+2
    //else ���s[i-dp[i-1]-1]=='(' dp[i]=dp[i-1]+2
    int longestValidParenthesesDP(string s) {
        int sSize = s.size(), result = 0;
        if (sSize == 0 || sSize == 1)
            return 0;
        int* dp = new int[sSize];
        memset(dp, 0, sizeof(int) * sSize);
        for (int i = 0; i < sSize; i++) {
            //s[i]�������žͲ��������
            if (s[i] == ')') {
                //i==0�Ļ��Ͳ��������
                if (i - 1 >= 0) {
                    if (s[i - 1] == '(') {
                        if (i - 2 >= 0) {
                            dp[i] = dp[i - 2] + 2;
                            
                        }
                        else {
                            dp[i] = 2;
                        }
                        result = max(dp[i], result);
                    }
                    else {
                        int bombardPosition = i - dp[i - 1] - 1;
                        if (bombardPosition >= 0 && s[bombardPosition] == '(') {
                            int tk = (i - dp[i - 1] - 2) >= 0 ? dp[i - dp[i - 1] - 2] : 0;
                            dp[i] = dp[i - 1] + 2 + tk;
                            result = max(result, dp[i]);
                        }
                    }
                }
            }
        }
        delete[] dp;
        return result;
    }
    
    
 
};
//(())()
//-1 0 1 ����2 
//-1 0 ����3 pop 0
//int main() {
//    Solution ss;
//    ss.longestValidParentheses("((()))()");
//}