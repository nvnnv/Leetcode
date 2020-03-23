vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<unsigned long, vector<string>> xxoo;
	unsigned long seed = 2;
	for (string& s : strs)
	{
		unsigned long i = 1;
		unsigned long t1 = 1, t2 = 2;
		for (auto c : s)
		{
			// Hash function; if occurring collision, increase power exponent
			t2 = c - 96;
			t1 += t2*t2*t2*t2 * c;
		}
		if (xxoo.count(t1) == 0)
		{
			vector<string> xo;
			xo.push_back(s);
			xxoo[t1] = xo;
		}
		else {
			xxoo[t1].push_back(s);
		}
	}
	vector<vector<string>> ans;
	for (auto i : xxoo)
	{
		ans.push_back(i.second);
	}
	return ans;
}
