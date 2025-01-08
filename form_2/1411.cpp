class Solution {
public:

    long long dp[5005][2];
    int MOD = 1e9 + 7;

    int numOfWays(int n) {
        								//dp[i][0] = ways to colour the row in 2 colours	e.g: R G R
        dp[0][0] = dp[0][1] = 6;			// dp[i][1]= ways to colour the row in 3 colours	e.g: R G Y	
        for (int i = 1; i < n; i++)
        {
            // colour current row with 2 colours: 
            //	if the previous row is coloured with 2 colours then there are 3 ways to colour the curent row with 2 colours 
            //	if the previous row is coloured with 3 colours then there are 2 ways to colour the curent row with 2 colours
            dp[i][0] = ((3 * dp[i - 1][0]) % MOD + (2 * dp[i - 1][1]) % MOD)%MOD;

            //colour current row with 3 colours:
            //	if the previous row is coloured with 2 colours then there are 2 ways to colour the curent row with 2 colours 
            //	if the previous row is coloured with 3 colours then there are 2 ways to colour the curent row with 2 colours
            dp[i][1] = ((2 * dp[i - 1][0]) % MOD + (2 * dp[i - 1][1]) % MOD)%MOD;
        }
        // ans will be total number of ways to colour the row with 2 colours and 3 colours
        return (dp[n - 1][0] + dp[n - 1][1])%MOD;
    }
};