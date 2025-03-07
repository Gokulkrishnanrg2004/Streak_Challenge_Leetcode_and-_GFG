/*
2523. Closest Prime Numbers in Range
Solved
Medium
Topics
Companies
Hint
Given two positive integers left and right, find the two integers num1 and num2 such that:

left <= num1 < num2 <= right .
Both num1 and num2 are prime numbers.
num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].

 

Example 1:

Input: left = 10, right = 19
Output: [11,13]
Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
Since 11 is smaller than 17, we return the first pair.
Example 2:

Input: left = 4, right = 6
Output: [-1,-1]
Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.
 

Constraints:

1 <= left <= right <= 106

*/


class Solution {
    public:
    vector<bool> sieve(int n)
    {
        vector<bool>isPrime(n+1,true);
        isPrime[0] = isPrime[1] = false;
        for(int i=2;i*i<=n;i++)
        {
            if(isPrime[i])
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }
    vector<int> closestPrimes(int left, int right) 
    {
        vector<bool>isPrime = sieve(right);
        vector<int>primes;

        for(int i = left;i<=right;i++)
        {
            if(isPrime[i])
            {
                primes.push_back(i);
            }
        }    
        if(primes.size() < 2) return {-1,-1};

        vector<int>result(2,-1);
        int mindiff = INT_MAX;
        int diff;
        for(int i = 1;i<primes.size();i++)
        {
            diff = primes[i] - primes[i-1];
            if(diff < mindiff)
            {
                mindiff = diff;
                result = {primes[i-1],primes[i]};
            }
        }
        return result;
    }
};
