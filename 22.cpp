/*
f(n) = M(f(n-1), f(1)) n>1 M: all legal matches of f(n-1) and f(1) 
the rule of () match: there are two directions, f(n-1)->f(1);making f(n-1) insert f(1) and f(1)->f(n-1); making f(1) insert f(n-1)
for "f(n-1)->f(1)" 3 situations 
  (),((,)),)(, meeting these 4 forms, f(1) inserts the middle of (),((,)),)(; 
  f(1) is put in front of f(n-1);
  f(1) is put in back of f(n-1);
 for "f(1)->f(n-1)" only 1 possibility
  f(n-1) is put the middle of f(1);
*/
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
