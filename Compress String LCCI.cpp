const int char_convert = 48;
string compressString(string S) {
	int len_s = S.size();
	if (len_s < 2) return S;
	
	string temp;
	string compress_s;
	int count_ele=1;
	for (int i = 1; i < len_s; ++i)
	{
		if (S[i] == S[i - 1])
		{
			++count_ele;
		}
		else
		{
			compress_s.push_back(S[i - 1]);
			if (count_ele < 10)
			{
				compress_s.push_back(count_ele + char_convert);
			}
			else
			{
                temp = "";
				while (count_ele)
				{
					temp.push_back(count_ele % 10 + char_convert);
					count_ele /= 10;
				}
				reverse(temp.begin(), temp.end());
				compress_s += temp;
			}
			count_ele = 1;
		}
	}
	compress_s.push_back(S[len_s - 1]);
	if (count_ele < 10)
	{
		compress_s.push_back(count_ele + char_convert);
	}
	else
	{
        temp = "";
		while (count_ele)
		{
			temp.push_back(count_ele % 10 + char_convert);
			count_ele /= 10;
		}
		reverse(temp.begin(), temp.end());
		compress_s += temp;
	}
	
	return len_s <= compress_s.size() ? S: compress_s;
}
