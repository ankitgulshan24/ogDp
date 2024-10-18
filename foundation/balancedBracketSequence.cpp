// Given a bracket sequence with ‘?’ at some places, you need to find the number of ways you can replace ‘?’ with ‘(‘ or ‘)’ to form a regular bracket sequence.
// A bracket sequence is called regular if it is possible to obtain the correct arithmetic expression by inserting characters + and 1 into this sequence.


// codeforces problem almost similar    https://codeforces.com/problemset/problem/26/B

// sample Input                // sample output 

// 5   no of testcase                          
// (??)                            2
// ??                               1
// ()()()                           1
// ???                              0
// ??????                           5


// Hint 1
// At any point, the number of ‘(‘ is always greater than equal to the number of ‘)’ and total count of ‘(‘ and ‘)’ in the string is equal.

// Hint 2
// Define dp[i][j] which denotes the number of ways to form a balanced bracket sequence such that the prefix sum till i is j. Denote ‘(‘ with 1 and ‘)’ with -1.

// Solution Approach
// For ?, consider both the cases for ‘(‘ and ‘)’. At any point, the prefix sum should not be negative. The answer would be dp[n][0] since the prefix sum should
//  be 0 at the end of the string.

// Time Complexity per test case: O(n2)


#include<bits/stdc++.h>
using namespace std;

using ll=long long 
int mod=1e9+7;
ll dp[1010][1010];

ll n
string s;
ll rec(int i,int k, string &s){
    // pruning
    if(k<0) return 0;

    // base case
    if(i==n){
        if(k==0) return 1;
        else return 0;
    }
    int ans=0;
    if(s[i]!='?'){
        if(s[i]=='('){
            ans=rec(i+1, k+1, s);
        }else if(s[i]==')'){
            ans=rec(i+1, k-1,s);
        }
    }else if(s[i]=='?'){
        ans=rec(i+1, k+1,s);
        ans=rec(i+1, k-1,s);
    }
    return ans;
}












































