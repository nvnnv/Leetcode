int findPairs(vector<int>& nums, int k) {
	int n = nums.size();
	if (n == 0 || n == 1) return 0;

	sort(nums.begin(), nums.end());
	int temp =0;
	int diff =0;
	int L = 0;
	int R = 0;
	int ans = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		temp = nums[i];
		if (i != n - 1)
		{
			if (nums[i + 1] == temp) continue;
		}
		diff = temp - k;
		L = 0;
		R = i - 1;
		while (L <= R)
		{
			temp = (L + R) / 2;
			if (nums[temp] < diff)
			{
				L = temp + 1;
				continue;
			}
			if (nums[temp] > diff)
			{
				R = temp - 1;
				continue;
			}
			if (nums[temp] == diff)
			{
				++ans;
				break;
			}
		}
	}
	return ans;
}
