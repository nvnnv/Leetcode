char firstUniqChar(string s) {
	int len_s = s.size();
	if (len_s == 0)
	{
		return ' ';
	}

	map<int, int> flag;
	for (auto c : s)
	{
		++flag[c];
	}
	for (auto c : s)
	{
		if (flag[c]==1) return c;
	}
	return ' ';
}
