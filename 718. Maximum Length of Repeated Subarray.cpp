int findLength(vector<int>& A, vector<int>& B) {
    vector<vector<int>> dp(B.size(), vector<int>(A.size(), 0));
    dp[0][0] = 1;
    int m = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = 0; j < B.size(); ++j)
        {
            if (A[i] == B[j])
            {
                if (i > 0 && j > 0) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = 1;
            }
            else dp[i][j] = 0;
            m = max(dp[i][j], m);
        }
    }
    return m;
}
