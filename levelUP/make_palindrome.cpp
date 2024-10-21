// leetcode 1312


// Given a string s. In one step you can insert any character at any index of the string.

// Return the minimum number of steps to make s palindrome.

// A Palindrome String is one that reads the same backward as well as forward.



class Solution {
public:

    int solve(int l, int r, string &s,  vector<vector<int>>&dp){
        if(l>=r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=0;
        
        if(s[l]!=s[r]){
            ans+=1+min(solve(l+1, r, s, dp),solve(l, r-1, s, dp) );
        }else{
            ans+=solve(l+1, r-1,s, dp);
        }
        
        return dp[l][r]=ans;
    }


    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(0, s.size()-1, s, dp);
        
    }
};