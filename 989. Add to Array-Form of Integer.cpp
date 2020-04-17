vector<int> addToArrayForm(vector<int>& A, int K) {
	vector<int> ans;
	int n = A.size();
	if (n == 0) return ans;
	int pro = 0;
	int base = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		base = K % 10 + A[i] + pro;
		ans.push_back(base % 10);
		pro = base / 10;
		K = K / 10;
	}
	if (pro == 1 && K==0)
	{
		ans.push_back(1);
	}
	else
	{
		while (K)
		{
			base = K % 10 + pro;
			ans.push_back(base % 10);
			pro = base / 10;
			K = K / 10;
		}
        if (pro == 1) ans.push_back(1);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
