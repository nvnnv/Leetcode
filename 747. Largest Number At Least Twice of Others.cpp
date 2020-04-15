int dominantIndex(vector<int>& nums) {
	int n = nums.size();

	if (n ==0) return -1;
	if (n == 1) return 0;
	int max1 = 0;
	int pos;
	for (int i = 0; i < n; ++i)
	{
		if (max1 < nums[i]) max1 = nums[i],pos=i;
	}
	if (max1 == 0) return -1;
	int max2 = max1;
	for (int j = 0; j < n; ++j)
	{
		if (nums[j] == max1) continue;
		if (max1 - nums[j] < max2) max2 = max1 - nums[j];
	}
	if (max1 - max2 == 0) return pos;
	return max1 / (max1 - max2) >= 2 ? pos : -1;
}
