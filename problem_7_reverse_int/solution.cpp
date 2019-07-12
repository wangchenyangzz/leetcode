// Given a 32-bit signed integer, reverse digits of an integer.
// 32位int值,翻转

#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int pop = 0;
        while (x != 0)
        {
            pop = x % 10;
            x = x / 10;
            if (x > INT_MAX / 10 || (x == INT_MAX / 10 && res > 7)) return 0;
            if (x < INT_MIN / 10 || (x == INT_MIN / 10 && res < -8)) return 0;
            res = res * 10 + pop;
        }
        return res;
    }

// 递归方法
//     int reverse(int x) {
//         if (x < 0) {
//             max = INT_MAX;
//             return -num(-x, 0);
//         } else {
//             max = pow(2,31) - 1;
//             return num(x, 0);
//         }
//     }
// private:
//     long num(int n, int bit) {
//         if (n / 10 == 0)
//         {
//             return n;
//         }
//         b++;
//         return num(n / 10, bit + 1) + n % 10 * pow(10, b - bit) > max ? 0 : num(n / 10, bit + 1) + n % 10 * pow(10, b - bit);
//     }
//     int b = 0;
//     int max = 0;
};

int main() {
    Solution solution;
    cout << solution.reverse(123456);
    return 0;
}