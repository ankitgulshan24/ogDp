// Description
// You are given N bricks in a line and M different coloured buckets of paint. You have to find the number of ways you can colour the brick wall such that 
// there are exactly K positions out of the N bricks such that it has a different colour from the brick wall on its immediate left. (except the first brick,
//  since there is no left brick). Print it modulo 10^9+7.

 

 

// Input Format
// The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

// The first and only line of each test case contains three space-separated integers N, M, K.

 

// Output Format
// For each test case, print the number of ways you can colour the brick wall satisfying the given condition % 10^9+7.

// Constraints
// 1≤ T ≤ 100

// 1≤ N, M ≤ 2000

// 0≤ K ≤ N-1

// It is guaranteed that the sum of N*K over all test cases does not exceed 4*108.



// Sample Input 1
// 3
// 3 2 2
// 2 2 1
// 3 5 0
// Sample Output 1
// 2
// 2
// 5




#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<long long>> memo;

long long solve(int i, int diff, int N, int M, int K) {
    // Base case: if we've placed all bricks
    if (i == N) {
        return (diff == K) ? 1 : 0; // We want exactly K differences
    }
    
    if (memo[i][diff] != -1) {
        return memo[i][diff];
    }

    long long ans = 0;

   
    if (i == 0) {
        ans = M * solve(i + 1, diff, N, M, K) % MOD; // Choose any color for the first brick
    } else {
        // Same color as previous
        ans = solve(i + 1, diff, N, M, K) % MOD; // No increase in diff

        // Different color from previous
        if (diff < K) {
            ans = (ans + (M - 1) * solve(i + 1, diff + 1, N, M, K) % MOD) % MOD; // Increase diff
        }
    }

    // Save the result and return
    return memo[i][diff] = ans;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        // Initialize memoization table
        memo.assign(N + 1, vector<long long>(K + 1, -1));

        // Call the recursive function starting with the first brick
        long long result = solve(0, 0, N, M, K);

        // Output the result modulo MOD
        cout << result % MOD << endl;
    }

    return 0;
}