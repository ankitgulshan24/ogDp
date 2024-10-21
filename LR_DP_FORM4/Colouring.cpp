// Genos recently installed the game Zuma on his phone. In Zuma there exists a line of n gemstones, the i-th of which has color ci. The goal of the
//  game is to destroy all the gemstones in the line as quickly as possible.

// In one second, Genos is able to choose exactly one continuous substring of colored gemstones that is a palindrome and remove it from the line. 
// After the substring is removed, the remaining gemstones shift to form a solid line again. What is the minimum number of seconds needed to destroy 
// the entire line?


// InputCopy
// 3
// 1 2 1
// OutputCopy
// 1
// InputCopy
// 3
// 1 2 3
// OutputCopy
// 3
// InputCopy
// 7
// 1 4 4 2 3 2 1
// OutputCopy
// 2


// 1 3 2 3 2 4 3 3 4 3 1
//       ||   => 1 step
// 1 3 2 3 2 3 1
//         ||=> 2 step
//         vanishes





// transition dp(i, j){
//     if i>j return 0
//     if(i==j) return 1

//     1+ dp(i+1, j )
//     if(s[i+1]==s[i]) 1+ dp(i+2, j)


//     min if(al==ax){
//         dp(l+1, x-1)+dp(x+1, r);    // yha pe +1 nhi hoga see in note book
//     }
// }





#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=505;
 
int n, a[maxn], d[maxn][maxn];
 
void read() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
}
 
void fun() {
	for (int len = 1; len <= n; len++) {
		for (int beg = 0, end = len - 1; end < n; beg++, end++) {
			if (len == 1) {
				d[beg][end] = 1;
			} else {
				d[beg][end] = 1 + d[beg + 1][end];
				if (a[beg] == a[beg + 1]) {
					d[beg][end] = min(1 + d[beg + 2][end], d[beg][end]);
				}
				for (int match = beg + 2; match <= end; match++) {
					if (a[beg] == a[match]) {
						d[beg][end] = min(d[beg + 1][match - 1] + d[match + 1][end], d[beg][end]);
					}
				}
			}
		}
	}
}
 
int main() {
	read();
	fun();
	printf("%d\n", d[0][n-1]);
	return 0;
}