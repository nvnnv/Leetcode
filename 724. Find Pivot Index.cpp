int pivotIndex(vector<int>& nums) {
	int n = nums.size();
	if (n ==0 ) return -1;
	int left = 0;
	int right = 0;
	for (int i = 1; i < n; ++i) right += nums[i];
	if (left == right) return 1;
	for (int i = 1; i < n; ++i)
	{
		left += nums[i-1];
		right -= nums[i];
		if (left == right) return i;
	}
	return -1;
}
