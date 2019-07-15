// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

// '.' 匹配任意单个字符
// '*' 匹配零个或多个前面的那一个元素
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

// 说明:

// s 可能为空，且只包含从 a-z 的小写字母。
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

#include <iostream>
using namespace std;

class Solution {
public:

    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(p.length()>1 && p[1]=='*')
            return isMatch(s,p.substr(2)) ||
                    (!s.empty() && (s[0]==p[0]||p[0]=='.') && isMatch(s.substr(1),p));
        else return !s.empty() && (s[0]==p[0]||p[0]=='.') &&
                    isMatch(s.substr(1),p.substr(1));
    }
};

int main() {
    Solution solution;
    cout << solution.isMatch("asda", "asda") << endl;
    return 0;
}

//public boolean isMatch(String text, String pattern) {
//    boolean[][] dp = new boolean[text.length() + 1][pattern.length() + 1];
//    dp[text.length()][pattern.length()] = true;
//    for (int i = text.length(); i >= 0; i--){
//        for (int j = pattern.length() - 1; j >= 0; j--){
//        boolean first_match = (i < text.length() &&
//                                   (pattern.charAt(j) == text.charAt(i) ||
//                                    pattern.charAt(j) == '.'));
//            if (j + 1 < pattern.length() && pattern.charAt(j+1) == '*'){
//                dp[i][j] = dp[i][j+2] || first_match && dp[i+1][j];
//            } else {
//                dp[i][j] = first_match && dp[i+1][j+1];
//            }
//        }
//    }
//    return dp[0][0];
//}
