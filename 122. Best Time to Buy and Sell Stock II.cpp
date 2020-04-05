int maxProfit(vector<int>& prices) {
	int n = prices.size();
	if (n == 0 || n == 1) return 0;
	/*
		
	*/
	int ans = 0;
	int min = prices[0];
	for (int i = 1; i < n; ++i)
	{
		if (min > prices[i]) min = prices[i];
		if (prices[i] <= prices[i - 1]) continue;
		ans = max(prices[i] - prices[i - 1] + ans, prices[i] - min);
	}
	return ans;
}
