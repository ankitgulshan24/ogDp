Description
You are standing on the lowest row of a chessboard and can only move, upwards and leftwards or upwards and rightwards. There is a predefined score on each cell 
of the chessboard. You can start from any cell in the lowest row and you have to reach the uppermost row such that your score is the maximum possible and it is
 divisible by K. You have to find the maximal score you can achieve.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains three space-separated integers N, M, and K - the length of the array.

Each of the next N lines contains M digits from 0-9 indicating the score at that cell.

Output Format
For each test case, if it is possible, you have to find the maximal score you can achieve. If it is impossible print -1.



// Sample Input 1
// 3
// 4 3 11
// 194
// 707
// 733
// 633
// 2 4 2
// 3916
// 9593
// 2 2 4
// 15
// 52
// Sample Output 1
// 22
// 18
// -1


#include<bits/stdc++.h>
using namespace std;

int dp[105][105][11];
int a[105][105];
int n,m,k;

bool isValid(int col){
	if(col > -1 and col < m) return true;
	return false;
}

int f(int row, int col, int rem){
	if(row == -1){
		if(rem) return -1e9;
		else return 0;
	}

	if(dp[row][col][rem] != -1) return dp[row][col][rem];

	int ans = -1e9;
	if(isValid(col - 1)){
		ans = max(ans, a[row][col] + f(row - 1, col - 1, (rem + a[row][col]%k)%k));
	}
	if(isValid(col + 1)){
		ans = max(ans, a[row][col] + f(row - 1, col + 1, (rem + a[row][col]%k)%k));
	}
	return dp[row][col][rem] = ans;
}

/* Logic */
void solve(){
	cin >> n >> m >> k;
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			a[i][j] = s[j] - '0';
		}
	}

	int ans = -1e9;
	memset(dp, -1 , sizeof(dp));
	for(int col = 0; col < m; col++){
		ans = max(f(n-1, col, 0) , ans);
	}
	if(ans < 0) cout << -1 << "\n";
	else cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tests = 1;
    cin >> tests;
    while(tests--){
        solve();
    }
}