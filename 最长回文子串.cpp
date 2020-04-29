// 40ms
string longestPalindrome(string s) {
	int len_s = s.size();
	string ans = s.substr(0,1);
	int j=0, k=0;
	for (int i = 0; i < len_s; ++i) {

		if (i+1 < len_s&&s[i] == s[i + 1])
		{
			j = i;
			k = i+1;
			while (j >= 0 && k < len_s && s[j] == s[k])
			{
				--j;
				++k;
			}
			++j;
			--k;
			if (k - j + 1 > ans.size())
			{
				ans = s.substr(j, k - j + 1);
			}
		}
		if (i-1>=0 && i+1<len_s && s[i - 1] == s[i + 1])
		{
			j = i - 1;
			k = i + 1;
			while (j >= 0 && k < len_s && s[j] == s[k])
			{
				--j;
				++k;
			}
			++j;
			--k;
			if (k - j + 1 > ans.size())
			{
				ans = s.substr(j, k - j + 1);
			}
		}
	}
	return ans;
}
