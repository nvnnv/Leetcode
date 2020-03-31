void dfs(vector<int>& candi, int target, int pos, vector<vector<int>>& ans, vector<int>& cur)
{
	if (target == 0)
	{
		ans.push_back(cur);
	}
	else
	{
		for (int i = pos; i < candi.size()&& candi[i]<=target; ++i)
		{
			if (i != pos)
			{
				if (candi[i - 1] == candi[i]) continue;
			}
			cur.push_back(candi[i]);
			dfs(candi, target-candi[i], i + 1, ans, cur);
			cur.pop_back();
		}
	}
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> ans;
	int len = candidates.size();
	if (len == 0)
	{
		return ans;
	}

	sort(candidates.begin(), candidates.end());
	vector<int> cur;
	dfs(candidates, target, 0, ans, cur);
	return ans;
}
