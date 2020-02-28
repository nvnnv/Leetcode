// someone only spends 8856KB memory but I use 11.5MB, I think about it for a long time and I donot understand.
string longestCommonPrefix(vector<string>& strs) {
	if (strs.size() == 0) return "";
	auto& str_1 = strs[0];
	int len = strs.size();
	int len_1 = str_1.size();
	char c, d;
	bool flag = false;
	string ans = "";
	for (int i=0;i<len_1;++i)
	{
		c = str_1[i];
		for (int j = 1; j < len; ++j)
		{
			if (i >= strs[j].size())
			{
				flag = true;
				break;
			}
			d = strs[j][i];
			if (c != d)
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			break;
		}
		else {
			ans.push_back(c);
		}
	}
	return ans;
}
