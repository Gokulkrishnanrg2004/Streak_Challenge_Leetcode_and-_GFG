/*
2965. Find Missing and Repeated Values
Solved
Easy
Topics
Companies
You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

 

Example 1:

Input: grid = [[1,3],[2,2]]
Output: [2,4]
Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].
Example 2:

Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
Output: [9,5]
Explanation: Number 9 is repeated and number 5 is missing so the answer is [9,5].
*/
class Solution {
    public:
    int finddup(vector<int>&arr)
    {
        int result = 0;
        unordered_set<int>seen;
        for(int num : arr)
        {
            if(seen.find(num) != seen.end())
            {
                return num;
            }
            seen.insert(num);
        }
        return result;
    }
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<int>result;
        for(auto r:grid)
        {
            for(auto c:r)
            {
                result.push_back(c);
            }
        }    
        sort(result.begin(),result.end());
        int dup1 = finddup(result);
        result.erase(unique(result.begin(),result.end()),result.end());
        int dup2;
        for(int i=0;i<n*n;i++)
        {
            if (i >= result.size() || result[i] != i + 1) {
                dup2 = i + 1;
                break; 
            }
        }
        return {dup1,dup2};

    }
};
