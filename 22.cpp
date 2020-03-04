// 12ms 10.5MB
unsigned pare_num_mapp(string& str)
{
	unsigned i = 0;
	for (auto c : str)
	{
		if (c == ')') i = i | 1;
		i <<= 1;
	}
	i >>= 1;
	return i;
}
vector<vector<string>> ans_set;
vector<string> generateParenthesis(int n) {
	vector<string> ans;
	if (n <= 0) return ans;

	// init
	vector<string> ans_1 = { "()" };
	vector<string> ans_2 = { "()()","(())" };
	ans_set.push_back(ans_1);
	ans_set.push_back(ans_2);

	set<unsigned> cur_set_map;
	// init end

	// body
	string match_base = "()";
	vector<string> match_divisor;
	string temp;
	unsigned temp_f;
	for (int i = 3; i <= n; ++i)
	{
		vector<string> ans_i;
		match_divisor = ans_set[i-2];
		for (auto s : match_divisor)
		{
			// base->disvior
			temp = match_base + s;
			temp_f = pare_num_mapp(temp);
			if (cur_set_map.count(temp_f) == 0) {
				cur_set_map.insert(temp_f);
				ans_i.push_back(temp);
			}

			temp = s + match_base;
			temp_f = pare_num_mapp(temp);
			if (cur_set_map.count(temp_f) == 0) {
				cur_set_map.insert(temp_f);
				ans_i.push_back(temp);
			}
			
			int j = 0, k = 1;
			int len = s.size();
			while (k < len)
			{
				// there must be injury of efficiency in a big data-scale and many repeated judge-cases
				temp = s;
				temp.insert(k, "()");
				temp_f = pare_num_mapp(temp);
				if (cur_set_map.count(temp_f) == 0) {
					cur_set_map.insert(temp_f);
					ans_i.push_back(temp);
				}
				++j;
				++k;
			}

			// disvior->base
			temp = "(" + s + ")";
			temp_f = pare_num_mapp(temp);
			if (cur_set_map.count(temp_f) == 0) {
				cur_set_map.insert(temp_f);
				ans_i.push_back(temp);
			}
		}
		ans_set.push_back(ans_i);
	}
	return ans_set[n-1];
}
