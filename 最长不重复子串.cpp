// 0ms
int lengthOfLongestSubstring(string s) {
	int len_s = s.size();
	if(len_s==0) return 0;
	unordered_map<int, int> flag;
	for (auto c : s)
	{
		flag[c] = -1;
	}
	flag[s[0]] = 0;
	int sub_begin = 0;
	int sub_cur = 1;
	int temp_ans = 1;
	int ans = 0;
	for (sub_cur; sub_cur < len_s; ++sub_cur)
	{
		int pos = flag[s[sub_cur]];
		if (pos == -1)
		{
			flag[s[sub_cur]] = sub_cur;
			++temp_ans;
		}
		else
		{
			if (pos < sub_begin)
			{
				flag[s[sub_cur]]=sub_cur;
				++temp_ans;
			}
			else
			{
				// updating operation
				ans = temp_ans > ans ? temp_ans : ans;
				sub_begin = pos + 1;
				temp_ans = sub_cur - pos;
				flag[s[sub_cur]] = sub_cur;
			}
		}
	}
	ans = temp_ans > ans ? temp_ans : ans;
	return ans;
}
// 40ms
int lengthOfLongestSubstring(string s) {
	int len_s = s.size();
	if(len_s==0) return 0;
	unordered_map<int, int> flag;
	for (auto c : s)
	{
		flag[c] = -1;
	}
	flag[s[0]] = 0;
	int sub_begin = 0;
	int sub_cur = 1;
	int temp_ans = 1;
	int ans = 0;
	for (sub_cur; sub_cur < len_s; ++sub_cur)
	{
		int pos = flag[s[sub_cur]];
		if (pos == -1)
		{
			flag[s[sub_cur]] = sub_cur;
			++temp_ans;
		}
		else
		{
			if (pos < sub_begin)
			{
				flag[s[sub_cur]]=sub_cur;
				++temp_ans;
			}
			else
			{
				// updating operation
				ans = temp_ans > ans ? temp_ans : ans;
				sub_begin = pos + 1;
				temp_ans = sub_cur - pos;
				flag[s[sub_cur]] = sub_cur;
			}
		}
	}
	ans = temp_ans > ans ? temp_ans : ans;
	return ans;
}
