// dp
int countSquares(vector<vector<int>>& matrix) {
    vector<vector<int>> dp;
    dp = matrix;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            if (i - 1 >= 0 && j - 1 >= 0 && dp[i][j] > 0)
            {
                int temp = dp[i - 1][j - 1];
                int k = 1;
                while (k <= temp)
                {
                    if (matrix[i][j-k] == 0 || matrix[i-k][j] == 0)
                    {
                        break;
                    }
                    ++k;
                }
                dp[i][j] += dp[i - 1][j - 1] - (temp-k+1);
            }
        }
    }
    int sum = 0;
    for (auto v : dp)
    {
        for (auto i : v)
        {
            sum += i;
        }
    }
    return sum;
}
