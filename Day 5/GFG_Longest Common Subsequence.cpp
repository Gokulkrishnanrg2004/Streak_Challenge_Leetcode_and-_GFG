/*
Longest Common Subsequence
Difficulty: MediumAccuracy: 41.68%Submissions: 298K+Points: 4
Given two strings s1 and s2, return the length of their longest common subsequence (LCS). If there is no common subsequence, return 0.

A subsequence is a sequence that can be derived from the given string by deleting some or no elements without changing the order of the remaining elements. For example, "ABE" is a subsequence of "ABCDE".

Examples:

Input: s1 = "ABCDGH", s2 = "AEDFHR"
Output: 3
Explanation: The longest common subsequence of "ABCDGH" and "AEDFHR" is "ADH", which has a length of 3.
Input: s1 = "ABC", s2 = "AC"
Output: 2
Explanation: The longest common subsequence of "ABC" and "AC" is "AC", which has a length of 2.
Input: s1 = "XYZW", s2 = "XYWZ"
Output: 3
Explanation: The longest common subsequences of "XYZW" and "XYWZ" are "XYZ" and "XYW", both of length 3.
Constraints:
1<= s1.size(), s2.size() <=103
Both strings s1 and s2 contain only uppercase English letters.


*/

class Solution {
    public:
    vector<vector<int>>memo;
    int lcsrec(string& s1,string& s2,int m,int n)
    {
        if(m == 0 || n == 0)
            return 0;
        
        if(memo[m][n] != -1) return memo[m][n];
        
        if(s1[m-1] == s2[n-1])
            return memo[m][n] = 1 + lcsrec(s1,s2,m-1,n-1);
            
        else 
            return memo[m][n] = max(lcsrec(s1,s2,m,n-1),lcsrec(s1,s2,m-1,n));
    }
    int lcs(string &s1, string &s2) 
    {
        int m = s1.size(),n = s2.size();
        memo.assign(m + 1, vector<int>(n + 1, -1));
        return lcsrec(s1,s2,m,n);
    }
    
};
