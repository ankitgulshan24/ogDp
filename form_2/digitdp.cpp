
const int N = 1e4 + 5, M = 105, mod = 1e9 + 7, inf = 1e18;

string A, B;
int n, d, dp[N][2][2][M];

int go(int pos, bool bigA, bool smallB, int rem){
    if(pos >= n)
        return rem % d == 0;

    int &ans = dp[pos][bigA][smallB][rem];
    if(~ans)
        return ans;
    ans = 0;
    for(int i = 0; i < 10; i++){
        if(!bigA && i < A[pos] - '0')   continue;
        if(!smallB && i > B[pos] - '0') continue;

        ans = (ans + go(pos + 1, bigA || (i > A[pos] - '0'), smallB || (i < B[pos] - '0'), (rem + i)%d)) % mod;
    }
    return ans;
}