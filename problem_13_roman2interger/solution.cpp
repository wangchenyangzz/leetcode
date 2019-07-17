// 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

// 字符          数值
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

// 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

// I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
// X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
// C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
// 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
#include <iostream>
using namespace std;

class Solution {
public:

    //优化方案
    int romanToInt1(string s) {
        int end=0;
        string cha=s;
        // char[] cha = s.toCharArray();
        for(int i=s.length()-1;i>=0;i--){
            if(cha[i]=='I')
                end+=1;
            else if(cha[i]=='V')end+=(i-1)>=0&&cha[i-1]=='I'?4+i-i--:5;
            else if(cha[i]=='X')end+=(i-1)>=0&&cha[i-1]=='I'?9+i-i--:10;
            else if(cha[i]=='L')end+=(i-1)>=0&&cha[i-1]=='X'?40+i-i--:50;
            else if(cha[i]=='C')end+=(i-1)>=0&&cha[i-1]=='X'?90+i-i--:100;
            else if(cha[i]=='D')end+=(i-1)>=0&&cha[i-1]=='C'?400+i-i--:500;
            else if(cha[i]=='M')end+=(i-1)>=0&&cha[i-1]=='C'?900+i-i--:1000;
        }
        
        return end<4000?end:0;
    }

    /**
     * 首想方法
     */
    int romanToInt(string s) {
        string one[4] = {"M", "C", "X", "I"};
        string four[4] = {"", "CD", "XL", "IV"};
        string nine[4] = {"", "CM", "XC", "IX"};
        string five[4] = {"", "D", "L", "V"};
        int thousand = 0;
        int hundred = 0;
        int teen =0;
        int digit = 0;
        int index = 0;
        for (size_t i = 0; i < 4; i++)
        {
            if(four[i] == s.substr(index,2)) {
               switch (i)
                {
                    case 0:
                        thousand = 4;
                        break;
                    
                    case 1:
                        hundred = 4;
                        break;

                    case 2:
                        teen = 4;
                        break;

                    case 3:
                        digit = 4;
                        break;
                }
                index += 2;
                continue;
            }

            if(nine[i] == s.substr(index,2)) {
               switch (i)
                {
                    case 0:
                        thousand = 9;
                        break;
                    
                    case 1:
                        hundred = 9;
                        break;

                    case 2:
                        teen = 9;
                        break;

                    case 3:
                        digit = 9;
                        break;
                }
                index += 2;
                continue;
            }

            if(five[i] == s.substr(index,1)) {
                switch (i)
                {
                    case 0:
                        thousand = 5;
                        break;
                    
                    case 1:
                        hundred = 5;
                        break;

                    case 2:
                        teen = 5;
                        break;

                    case 3:
                        digit = 5;
                        break;
                }
                index++;
                while (one[i] == s.substr(index,1))
                {
                    switch (i)
                    {
                        case 0:
                            thousand++;
                            break;
                        
                        case 1:
                            hundred++;
                            break;

                        case 2:
                            teen++;
                            break;

                        case 3:
                            digit++;
                            break;
                    }
                    index++;
                }
            }

            while (one[i] == s.substr(index,1))
            {
                switch (i)
                {
                    case 0:
                        thousand++;
                        break;
                    
                    case 1:
                        hundred++;
                        break;

                    case 2:
                        teen++;
                        break;

                    case 3:
                        digit++;
                        break;
                }
                index++;
            }
        }
        return thousand * 1000 + hundred * 100 + teen * 10 + digit ;        
    }
};

int main() {
    Solution solution;
    cout << solution.romanToInt("III") << endl;
}