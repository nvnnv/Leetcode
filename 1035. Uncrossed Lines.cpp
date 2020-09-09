int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    vector<vector<int>> dp(A.size(), vector<int>(B.size()));
    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = 0; j < B.size(); ++j)
        {
            if (i == 0 && j == 0 && A[i]==B[j])
            {
                dp[i][j] = 1;
            }
            if (i != 0 && j != 0)
            {
                if (A[i] == B[j])
                {
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, max(dp[i - 1][j], dp[i][j - 1]));
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
            if (j == 0 && i != 0)
            {
                dp[i][j] = A[i]==B[j] ? 1 : dp[i - 1][j];
            }    
            if (i == 0 && j != 0)
            {
                dp[i][j] = A[i]==B[j] ? 1: dp[i][j - 1];
            } 
        }
    }
    return dp[A.size()-1][B.size()-1];
}
