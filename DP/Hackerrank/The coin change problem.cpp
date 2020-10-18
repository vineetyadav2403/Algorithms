//https://www.hackerrank.com/challenges/coin-change/problem?isFullScreen=true

/*
 * Complete the 'getWays' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. LONG_INTEGER_ARRAY c
 */
long getWays(int n, vector<long> c) {
    long x,y;
    vector<vector<long>> dp(c.size(),vector<long>(n+1,1));
    for(long i = 0;i<c.size();i++){
        for(long j=1;j<=n;j++){
            x = (i>0) ? dp[i-1][j]:0;
            y = (j-c[i]>=0)?dp[i][j-c[i]]:0;
            dp[i][j] = x+y;
        }
    }
    return dp[c.size()-1][n];
}
