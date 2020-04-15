double findMaxAverage(vector<int>& nums, int k) {
	int n = nums.size();
	if (n == 0) return 0;
	if (n == 1) return nums[0];

	double ans = 0.0;
	double ans_temp = 0.0;
	double sum = 0.0;
	int back = 0;

	for (int i = 0; i < k; ++i)
	{
		sum += nums[i];
	}
	ans = (double)sum / k;
	for (int i = k; i < n; ++i)
	{
		sum -= nums[back++];
		sum += nums[i];
		ans_temp = sum / k;
		if (ans < ans_temp) ans = ans_temp;
	}
	return ans;
}
