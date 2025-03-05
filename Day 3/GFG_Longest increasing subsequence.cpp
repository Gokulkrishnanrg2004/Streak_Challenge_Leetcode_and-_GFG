/*
Longest Increasing Subsequence
Difficulty: MediumAccuracy: 32.8%Submissions: 338K+Points: 4
Given an array arr[] of non-negative integers, the task is to find the length of the Longest Strictly Increasing Subsequence (LIS).

A subsequence is strictly increasing if each element in the subsequence is strictly less than the next element.

Examples:

Input: arr[] = [5, 8, 3, 7, 9, 1]
Output: 3
Explanation: The longest strictly increasing subsequence could be [5, 7, 9], which has a length of 3.
Input: arr[] = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
Output: 6
Explanation: One of the possible longest strictly increasing subsequences is [0, 2, 6, 9, 13, 15], which has a length of 6.
Input: arr[] = [3, 10, 2, 1, 20]
Output: 3
Explanation: The longest strictly increasing subsequence could be [3, 10, 20], which has a length of 3.
Constraints:
1 ≤ arr.size() ≤ 103
0 ≤ arr[i] ≤ 106


*/

class Solution {
  public:
    int lis(vector<int>& arr) 
    {
        vector<int>sub;
        for(int num : arr)
        {
            auto it = lower_bound(sub.begin(),sub.end(),num);
            
            if(it == sub.end())
            {
                sub.push_back(num);
            }
            else 
            {
                *it = num;
            }
        }
        return sub.size();
    }
};
