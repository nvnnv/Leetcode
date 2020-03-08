string ans[30] = { "1","11","21","1211","111221" };
string countAndSay(int n) {
	if (n <= 0) return "";
	if (n <= 5) return ans[n - 1];
	--n;
	for (int i = 5; i <= n; ++i)
	{
		auto s = ans[i - 1];
		string& cur = ans[i];
		int len_S = s.size();
		int j = 0, k = 1;
		int num = 1;
		for (k; k < len_S; ++k,++j)
		{
			if (s[j] != s[k])
			{
				cur.push_back(num + 48);
				cur.push_back(s[j]);
				num = 0;
			}
			++num;
		}
		if (s[k - 1] == s[k - 2])
		{
			cur.push_back(num + 48);
			cur.push_back(s[k - 1]);
		}
		else {
			cur.push_back('1');
			cur.push_back(s[k-1]);
		}
	}
	return ans[n];
}
