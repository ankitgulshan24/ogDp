
// Description
// You are given a string S with length N. Each character is assigned a cost for removing it. Find the minimum cost for removing characters such that 
// it does not contain any subsequence ‘hard’.

// Input Format
// The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

// The first line of each test case contains one integer N - the length of the array. 

// The second line of each test case contains a string S.

// The third line of each test case contains N space-separated integers - the cost of removing a character.

// Output Format
// For each test case, print the minimum cost for removing characters such that it does not contain any subsequence ‘hard’.




// Constraints
// 1≤ T ≤ 1000

// 1≤ N ≤ 10^5

// 1≤ Ai ≤ 10^9



// Sample Input 1
// 3
// 4
// abcd
// 1 2 3 4
// 10
// hhhaaarrdd
// 1 2 3 4 1 2 3 4 2 3
// 4
// hard
// 2 1 4 6
// Sample Output 1
// 0
// 5
// 1





// ==? general idea of this question       *******  find minimum no of operation such that it doesnot contain subsequence of t ********

// transition

// dp(level, x)-> min cost of remove from [i....n] such that hard is not present 

// base case => if(x==t.size()) return 0;

//                                             dp(leve+1, x) +cost[i]    // if any character of t is taken
//                     if(s[i]==t[x])          dp(level+1, x+1)
// dp(level, x)    
//                                             dp(level+1, x)





// itreative style 

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

signed main() {
   IOS
   int t;
   cin >> t;
   while(t--) {
       int n;
       string s;
       cin >> n >> s;
       int a[n];
       for (int i = 0; i < n; ++i) {
           cin >> a[i];
       }
       int dp[4] = {0};
       for (int i = 0; i < n; ++i) {
           if(s[i] == 'h') dp[0] += a[i];
           else if (s[i] == 'a') dp[1] = min(dp[0], dp[1] + a[i]);
           else if (s[i] == 'r') dp[2] = min(dp[1], dp[2] + a[i]);
           else if (s[i] == 'd') dp[3] = min(dp[2], dp[3] + a[i]);
       }
       cout << dp[3] << "\n";
   }
   return 0;
}```




