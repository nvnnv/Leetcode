int numEquivDominoPairs(vector<vector<int>>& dominoes) {
	map<pair<int, int>, int> flag;

	for (auto v : dominoes)
	{
		auto j = make_pair(v[1], v[0]);
		if (flag[j]) flag[j]++;
		else
		{
			auto i = make_pair(v[0], v[1]);
			flag[i]++;
		}
	}
	int ans = 0;
	for (auto p : flag)
	{
		ans += (p.second - 1) * p.second / 2;
	}
	return ans;
}
