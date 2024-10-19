// Description
// You are given N elements, in an array A. You can take any 2 consecutive elements a and b and merge them. On merging you get a single element 
// with value (a+b)%100 and this process costs you a*b. After merging you will place this element in place of those 2 elements.
 

// If the sequence is [A1, A2, A3, A4] and you merge A2 and A3, you incur a cost of A2*A3 and the array becomes [A1, (A2+A3)%100, A4].
 

// Find the Minimum cost to merge all the elements into a single element.

// Input Format
// The first line contains a single element N. 1 <= N <= 500

// The Second line contains N space separated integers, the Ai for the Array.  0 <= Ai < 100

// Output Format
// Output a single integer, the Minimum cost to Merge all the elements.

// Constraint

// sample input
// 3
// 1 2 4 
// Sample Output 
// 14


// Hint 1
// The answer is going to change as the elements are capped by Modulo. How do you design an efficient DP that takes care of all possible ordering? Think Backwards
//  from 1 element.


// Hint 2
// What if we keep DP(l,r) as the cost to merge the segment into one element, would that help? What would be the final value of the element if we merge range 
// [l,r]?


// Solution Approach
// The nice observation here is the value of the Final element remains fixed and is the sum of the range %100.

// So we can design a DP with the states
// DP(l,r) = minimum cost to merge the segment into one element.

// Now range (l,r) will form one element from 2 elements in the final step.
// So let's say the (l, mid) and (mid+1,r) range equivalents merge and produce the final element.

// So DP(l,r) = min(DP(l,mid) + DP(mid+1,r) + (sum(l,mid)%100)*(sum(mid+1,r)%100) ) for all mid in range [l,r).






#include<bits/stdc++.h>
using namespace std;

int n;
int arr[501];
int dp[501][501];

int rec(int l,int r){
    if(l==r){
        return 0;
    }
    if(dp[l][r]==-1){
        int ans = 1e9;
        int tot = 0;
        for(int i=l;i<=r;i++){
            tot+=arr[i];
        }
        int sum = 0;
        for(int mid=l;mid<r;mid++){
            sum += arr[mid];
            ans = min(ans,rec(l,mid)+rec(mid+1,r)+ ((sum)%100)*((tot-sum)%100));
        }
        dp[l][r]=ans;
    }
    return dp[l][r];
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1)<<endl;
}    

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int _t;cin>>_t;while(_t--)
    solve();
}```