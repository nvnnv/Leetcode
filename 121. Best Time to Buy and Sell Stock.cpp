int maxProfit(vector<int>& prices) {
	int n = prices.size();
	int max = 0;
	int min = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		if (prices[i] < min)
		{
			// save min value in the current subsequence
			min = prices[i];
		}
		if (prices[i] - min > max)
		{
			// compare the newest one with min
			max = prices[i] - min;
		}
	}
	return max;
}
