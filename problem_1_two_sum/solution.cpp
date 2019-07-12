// 英文
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// 中文
// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret(2,-1);
        map<int, int> map;
        int count = nums.size();
        for (int i = 0; i < count;i++)
        {
            int val = target - nums[i];
            if (map.count(val) > 0)
            {
                ret[0] = i;;
                ret[1] = map[val];
            }
            map[nums[i]] = i;
        }
        return ret;
    }
};

int main() {
    Solution solution;
    int arr[3] = {3, 2, 3};
    vector<int> vec(arr, arr + 3);
    vector<int> res = solution.twoSum(vec,6);
    vector<int>::iterator v = res.begin();
    while (v != res.end())
    {
        cout << "num: " << *v << endl;   
        v++;
    }
    
    return 0;
}