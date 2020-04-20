int waysToStep(int n) {
	if (n < 1) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	int base_mod = 1000000007;
	vector<int> dp(n+1);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= n; ++i)
	{
		dp[i] = ((dp[i - 1] + dp[i - 2])%base_mod + dp[i - 3])%base_mod;
	}
	return dp[n];
}
