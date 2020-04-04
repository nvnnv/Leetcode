int thirdMax(vector<int>& nums) {
	int n = nums.size();
	if (n == 2)
	{
		return nums[0] > nums[1] ? nums[0] : nums[1];
	}
	int n_max1 = INT_MIN;
	// find max
	for (auto i : nums)
	{
		if (n_max1 < i) n_max1 = i;
	}
	// find second max
	int n_max2 = INT_MIN;
	int flag = 0;
	for (auto i : nums)
	{
		if (n_max2 <= i && i < n_max1)
		{
			n_max2 = i;
			flag = 1;
		}
	}
	if (!flag)
	{
		n_max2 = n_max1;
	}
	// find 3th max
	int n_max3 = INT_MIN;
	flag = 0;
	for (auto i : nums)
	{
		if (i < n_max2 && n_max3 <= i)
		{
			n_max3 = i;
			flag = 1;
		}
	}
	if (!flag)
	{
		n_max3 = n_max1;
	}
	return n_max3;
}
