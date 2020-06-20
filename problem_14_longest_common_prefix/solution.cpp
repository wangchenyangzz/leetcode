class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        if(strs.empty()) return ret;
        if(strs.size() == 1) return strs[0];
        int j = 0;
        bool isEqual = true;
        int min = strs[0].size();
        for(int i = 1; i < strs.size(); ++ i) //找到最短字符串
        {
            if(strs[i].size() < min)
                min = strs[i].size();
        }

        while (j < min) {
            for (size_t i = 0; i < strs.size() - 1; i++)
            {
                isEqual = (strs[i][j] == strs[i+1][j] && isEqual);
            }
            if (!isEqual)
            {
                return ret;
            }
            ret += strs[0][j++];
        }
        return ret;      
    }
};
