vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> ans;
	set<int> flag;
	if (nums.size() == 0)
	{
		return ans;
	}

	sort(nums.begin(), nums.end());

	bool f = true;
	int len = nums.size();
	for (int i = 0; i < len-3; ++i)
	{
		if (i > 0)
		{
			if (nums[i] == nums[i - 1]) continue;
		}
		for (int j = i + 1; j < len - 2; ++j)
		{
			if (j > i + 1)
			{
				if (nums[j] == nums[j - 1]) continue;
			}

			int temp = target - nums[i] - nums[j];
			int B = j + 1;
			int E = len - 1;
			while (B < E)
			{
				if (nums[B] + nums[E] > temp)
				{
					--E;
					continue;
				}
				if (nums[B] + nums[E] < temp)
				{
					++B;
					continue;
				}
				else
				{
					vector<int> subAns = { nums[i],nums[j],nums[B], nums[E] };
					ans.push_back(subAns);
					++B;
					--E;
					while (B<E && (nums[B] + nums[E]) == temp)
					{
						if (nums[B] != nums[B - 1] && nums[E] != nums[E + 1])
						{
							vector<int> subAns = { nums[i],nums[j],nums[B], nums[E] };
							ans.push_back(subAns);
						}
						++B;
						--E;
					}
				}
			}
		}
	}
	return ans;
}
