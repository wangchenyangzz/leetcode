// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

// Example 1:
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:
// Input: "cbbd"
// Output: "bb"

#include <iostream>
using namespace std;

class Solution {
public:
    
    /**
     * 动态规划
     */
    /*
     string longestPalindrome(string s) {
     if (s == "") {
     return "";
     }
     int isPal[s.length()][s.length()];
     string res = "";
     for (int i = 0; i < s.length(); i++) {
     for (int j = i; j >= 0; j--) {
     isPal[i][j] = 0;
     if (s[i] == s[j] && (i - j < 2 || isPal[i-1][j+1])) {
     isPal[i][j] = 1;
     if (i + 1 - j > res.length()) {
     res = s.substr(j, i + 1 - j);
     }
     }
     }
     }
     return res;
     }
     */
    
    /**
     * 中心拓展法
     */
    string longestPalindrome(string s) {
        if (s == "" || s.length() < 1)
        {
            return "";
        }
        string res;
        int len1 = 0, len2 = 0;
        res = s[0];
        for (int i = 1; i < s.length(); i++)
        {
            len1 = expendAroundCenter(s, i, i);
            len2 = expendAroundCenter(s, i - 1, i);
            if (res.length() < 2 * len1 + 1)
            {
                res = s.substr(i - len1, 2 * len1 + 1);
            }
            
            if (res.length() < 2 * len2 + 2)
            {
                res = s.substr(i - len2 - 1, 2 * len2 + 2);
            }
        }
        return res;
    }
    
    int expendAroundCenter(const string& s, int left, int right) {
        int L = left;
        int R = right;
        while (L >= 0 && R < s.length() && s[L] == s[R]) {
            L--;
            R++;
        }
        return left - L - 1;
    }
};

int main() {
    Solution solution;
    cout << solution.longestPalindrome("baabad") << endl;
    return 0;
}