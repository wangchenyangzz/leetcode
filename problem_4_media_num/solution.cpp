// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
// You may assume nums1 and nums2 cannot be both empty.
// Example 1:
// nums1 = [1, 3]
// nums2 = [2]
// The median is 2.0
// 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
// 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
// 你可以假设 nums1 和 nums2 不会同时为空。
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int index1 = 0;
        int index2 = 0;
        int num = 0;
        int lastNum = 0;
        double mediaNum = 0;
        int flag = 0;
        int length = 0;
        int mediaIndex = (nums1.size() + nums2.size()) / 2;
        if( (nums1.size() + nums2.size()) % 2 == 0) {
            flag = 1;
        }
        for (size_t i = 0; i < nums1.size() + nums2.size(); i++)
        {
            if (index1 == nums1.size())
            {
                num = nums2[index2];
                index2++;
            }
            else if (index2 == nums2.size())
            {
                num = nums1[index1];
                index1++;
            }
            else {
                if (nums1[index1] < nums2[index2])
                {
                    num = nums1[index1];
                    index1++;
                } else {
                    num = nums2[index2];
                    index2++;
                }
            }
            if (!flag && i == mediaIndex)
            {
                mediaNum = num;
                break;
            }
            if (flag && i == mediaIndex) {
                mediaNum = (num + lastNum) / 2.0;
                break;
            }
            lastNum = num;
        }
        return mediaNum;
    }
};

int main() {
    Solution solution;
    int arr1[2] = {1,2};
    int arr2[2] = {3,4};
    vector<int> nums1(arr1, arr1 + 2);
    vector<int> nums2(arr2, arr2 + 2);
    cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
