#include "headerfile.h"
//刷题必写算法步骤
class Solution {
public:
    //保证“最大向后一位参考性”，感觉不需要dp，只需要最近状态值（错，应该还是需要dp存储状态值）
    //有“传导中断性”，可以理解为不能存档的游戏，死了就要从头开始闯关
    //失败了，呜呜呜，因为没办法确定position位和传导位
    //1、找出第一个左括号，记录下位置k
    //2、从k往左遍历，对于遇到的每一个左括号都判断其右边一位是否为
    //左括号，如果不是，那么这个位置上的合理括号值就是max[传导值,0]+1
    //如果是，那么判断对应位置上的字符是否为右括号，如果是，
    //更新dp值，如果不是，传导关系在这里破裂，从这个位置开始不可能
    //再有新的括号串，设为-1表示不可达，那么之后所有发现此处为-1的
    //的左括号都会将其dp值设为-1表示清零状态。
    //3、遇到右括号直接置之不理即可
    //返回：最大的dp值
    //((())) ((())
    //(()()) ((()))() ((())())
    // ((()))() ((())()) 的判断问题
    //一个position位和一个bombardPosition位置
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
    //else 如果s[i-dp[i-1]-1]=='(' dp[i]=dp[i-1]+2
    int longestValidParenthesesDP(string s) {
        int sSize = s.size(), result = 0;
        if (sSize == 0 || sSize == 1)
            return 0;
        int* dp = new int[sSize];
        memset(dp, 0, sizeof(int) * sSize);
        for (int i = 0; i < sSize; i++) {
            //s[i]是左括号就不用理会啦
            if (s[i] == ')') {
                //i==0的话就不用理会啦
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
//-1 0 1 遇到2 
//-1 0 遇到3 pop 0
//int main() {
//    Solution ss;
//    ss.longestValidParentheses("((()))()");
//}