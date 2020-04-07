int findUnsortedSubarray(vector<int>& nums) {
	int n = nums.size();
	if (n == 0 || n == 1) return 0;

	int f = 0;
	int e = 0;
	int min = INT_MAX;
	int max = INT_MIN;
	int temp = 0;
	// find the maximum not following ascending order
	for (int i = 1; i < n; ++i)
	{
		if (nums[i]<max)
		{
			e = i;
			continue;
		}
		temp = nums[i-1];
		if (nums[i] < temp&&max<temp)
		{
			max = temp;
			e = i;
		}
	}
	// find the minimum not following ascending order
	for (int i = n - 2; i >= 0; --i)
	{
		if (nums[i] > min)
		{
			f = i;
		}
		temp = nums[i+1];
		if (nums[i] > temp&& min > temp)
		{
			min = temp;
			f = i;
		}
	}
	// substract of the maximum and minimum is the answer
	return f==e ? 0 :e - f+1;
}
