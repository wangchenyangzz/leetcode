// 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
// 示例 1:
// 输入: 121
// 输出: true
// 示例 2:
// 输入: -121
// 输出: false
// 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) return true;
        if(x < 0) return false;
        int num = 1;
        int len = 0;
        while(x)
        {
            x/=10;
            num *= 10;
            len++;
        }
        int val_left = x;
        int val_right = x;
        for (size_t i = 0; len / 2; i++)
        {
           if (val_left / num != val_right % 10)
           {
               return false;
           }
           val_left -= num;
           val_right /= 10;
           num /= 10;
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.isPalindrome(123) << endl;
    return 0;
}

