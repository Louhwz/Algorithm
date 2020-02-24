#include "headerfile.h"
class Solution {
public:
    string addBinary(string a, string b) {
		string res = "";
		int carry = 0;
		int aSize = a.size() - 1, bSize = b.size() - 1;
		while (aSize >= 0 && bSize >= 0) {
			int temp = a[aSize] - '0' + b[bSize] - '0';
			temp += carry;
			res = to_string(temp % 2)  + res;
			carry = temp / 2;
			aSize--, bSize--;
		}
		while (aSize >= 0) {
			int temp = a[aSize] - '0' + carry;
			res = to_string(temp % 2) + res;
			carry = temp / 2;
			aSize--;
			if (carry == 0) {
				res = a.substr(0, aSize + 1) + res;
				break;
			}
		}
		while (bSize >= 0) {
			int temp = b[bSize] - '0' + carry;
			res = to_string(temp % 2) + res;
			carry = temp / 2;
			bSize--;
			if (carry == 0) {
				res = b.substr(0, bSize + 1) + res;
				break;
			}
		}
		if (carry)
			res = "1" + res;
		return res;
    }
};
//int main() {
//	Solution().addBinary("100", "110010");
//}