// 12ms 9.3MB
int strStr(string haystack, string needle) {
	if (needle == "") return 0;
	
	auto len_haystack = haystack.size();
	auto len_needle = needle.size();
	auto t = needle[0];
	int loop_limit = len_haystack - len_needle;
	bool f = true;
	for (int i=0;i<=loop_limit;++i)
	{
		if (haystack[i] == t)
		{
			int temp = i+1;
			for (int j = 1; j < len_needle; ++j, ++temp)
			{
				if (haystack[temp] != needle[j])
				{
					f = false;
					break;
				}
			}
			if (f) return i;
		}
	}
	return -1;
}
