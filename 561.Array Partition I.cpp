int arrayPairSum(vector<int>& nums) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	sort(nums.begin(), nums.end());
	int ans = 0;
	for (int i = 0; i < nums.size(); i+=2)
	{
		ans += nums[i];
	}
	return ans;
}
