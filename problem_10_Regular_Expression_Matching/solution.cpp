// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

// '.' 匹配任意单个字符
// '*' 匹配零个或多个前面的那一个元素
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

// 说明:

// s 可能为空，且只包含从 a-z 的小写字母。
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // 回溯法
     bool isMatch1(string s, string p) {
         if(p.empty()) return s.empty();
         if(p.length()>1 && p[1]=='*')
             return isMatch(s,p.substr(2)) ||
                     (!s.empty() && (s[0]==p[0]||p[0]=='.') && isMatch(s.substr(1),p));
         else return !s.empty() && (s[0]==p[0]||p[0]=='.') &&
                     isMatch(s.substr(1),p.substr(1));
     }
    
    // "mississippi"
    // "mis*is*p*."
    
    
    
    //动态规划
    bool isMatch(string s,string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, 0));
        dp[s.length()][p.length()] = 1;
        for (int i = s.length(); i >= 0; i--) {
            for (int j = p.length() - 1; j >= 0; j--) {
                bool firstMatch = (i < s.length() && (s[i] == p[j] || p[j] == '.'));
                if (j < p.length() - 1 && p[j+1] == '*')
                {
                    dp[i][j] = firstMatch || dp[i][j + 2] && (i + 1 <= s.length() && dp[i + 1][j]);
                } else {
                    dp[i][j] = firstMatch && dp[i+1][j+1];
                }
                
            }
        }
        for (int i = 0; i <= s.length(); i++) {
            for (int j = 0; j <= p.length(); j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[0][0];
    }
};

int main() {
    Solution solution;
    cout << solution.isMatch("aa", "a*") << endl;
    return 0;
}
