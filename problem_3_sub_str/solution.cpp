// Given a string, find the length of the longest substring without repeating characters.
// Example 1:
// Input: "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
// 示例 1:
// 输入: "abcabcbb"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n =s.length();
        map<char,int> indexMap;
        map<char,int>::iterator it;
        int res = 0, index = 0;
        for (int i = 0; i < n; i++)
        {
            if ((it = indexMap.find(s[0])) != indexMap.end())
            {
                index = max(index, it->second + 1);
                cout << index << endl;
            }
            indexMap[s[i]] = i + 1;
            res = max(res, i + 1 - index);
        }
        return res;
    }
};

int main() {
    Solution solution;
    int len = solution.lengthOfLongestSubstring("pwwkew");
    cout << len << endl;
    return 0;
}
