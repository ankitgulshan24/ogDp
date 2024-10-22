// 1416. Restore The Array

// A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits s and all 
// we know is that all integers in the array were in the range [1, k] and there are no leading zeros in the array.

// Given the string s and the integer k, return the number of the possible arrays that can be printed as s using the mentioned program. Since the answer may
//  be very large, return it modulo 109 + 7.



//similar q 1977 2478



class Solution {
public:
int n;
int MOD= 1e9+7;


    int solve(int start , string &s, int &k, vector<int>&dp){
        // base case 
        if(s[start]=='0') return dp[start] =0;
        if(start ==n) return dp[start]=1;
        if(dp[start]!= -1) return dp[start];
        

        long long num =0;
        long long ans=0;
        for(int end = start ; end <n; end++){
            num= num*10+ (s[end]-'0');
            if(num>k) break;
            ans+= solve(end+1, s,k, dp);
        }
        return dp[start]= ans%MOD;


    }
    int numberOfArrays(string s, int k) {
        n= s.length();
        vector<int>dp(n+1, -1);
         return solve(0, s, k, dp);
    }
};
 