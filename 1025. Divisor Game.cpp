// DP
bool divisorGame(int N) {
    int dp[1001];
    for (int i = 0; i < 1001; ++i)
    {
        dp[i] = 11111;
    }
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    for (int i = 4; i <= N; ++i)
    {
        int t = i;
        for (int j = i - 1; j > 0; --j)
        {
            if (i % j == 0) dp[i] = min(dp[i], dp[i - j]);
        }
        dp[i] = !dp[i];
    }
    return dp[N];
}

//game theory
bool divisorGame(int N) {
    if(N % 2 == 0) return 1;
    else return 0;
}
