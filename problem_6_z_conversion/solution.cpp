// 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
// 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
// L   C   I   R
// E T O E S I I G
// E   D   H   N
// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
// 请你实现这个将字符串进行指定行数变换的函数：
// string convert(string s, int numRows);
// 示例 1:
// 输入: s = "LEETCODEISHIRING", numRows = 3
// 输出: "LCIRETOESIIGEDHN"
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * 自行实现
     */
    // string convert(string s, int numRows) {
    //     if (numRows < 2) {
    //         return s;
    //     }
    //     char conv[s.length()][numRows];
    //     memset(conv,0,sizeof(conv));
    //     int index = 0;
    //     int c = 0, r = 0;
    //     string res;
    //     while (index < s.length()) {
    //         if (c % (numRows -1) == 0) {
    //             conv[c][r] = s[index];
    //             if (r == numRows - 1) {
    //                 c++;
    //                 r--;
    //             } else {
    //                 r++;
    //             }
    //             index++;
    //             continue;
    //         }
    //         conv[c][r] = s[index];
    //         c++;
    //         r--;
    //         index++;
    //     }
    //     for (int i = 0; i < numRows; i++) {
    //         for (int j = 0; j < s.length(); j++) {
    //             if (conv[j][i] != 0) {
    //                 res += conv[j][i];
    //             }
    //         }
    //     }
    //     return res;
    // }
    /*
    按行排序
     */
    // string convert(string s, int numRows) {
    //     if (numRows < 2) {
    //         return s;
    //     }
    //     vector<string> rows(min(numRows, (int)s.length()));
    //     int curRow = 0;
    //     bool isDown = false;
    //     string res;
    //     for (char c : s) {
    //         rows[curRow] += c;
    //         if (curRow == 0 || curRow == numRows - 1) {
    //             isDown = !isDown;
    //         }
    //         isDown?curRow++:curRow--;
    //     }
    //     for (string s: rows) {
    //         res += s;
    //     }
    //     return res;
    // }

    string convert(string s, int numRows) {
        if (numRows < 2) {
            return s;
        }
        vector<string> rows(min(numRows, (int)s.length()));
        int curRow = 0;
        bool isDown = false;
        string res;
        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) {
                isDown = !isDown;
            }
            isDown?curRow++:curRow--;
        }
        for (string s: rows) {
            res += s;
        }
        return res;
    }
};
int main() {
    Solution solution;
    cout << solution.convert("LEETCODE.,ISHIRING", 3) << endl;
    return 0;
    }
