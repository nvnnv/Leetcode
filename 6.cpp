// 16ms 10.4MB
string convert(string s, int numRows) {
	if (s == "") return "";
	if (numRows == 1) return s;

	string ans;
	int pos = 0, offset = 0;
	int len = s.size();
	const int dist_offset = 2*numRows-2;
	for (int i = numRows; i > 0; --i)
	{
		int temp = pos;
		// calculate the (numRows-i+1)-th line
		ans.push_back(s[temp]);
		temp = temp + dist_offset;
		if (offset == 0)
		{
			// the first line or the last line
			while (temp < len)
			{
				ans.push_back(s[temp]);
				temp = temp + dist_offset;
			}
		}
		else
		{
			// middle lines
			while (true)
			{
				if (temp - offset < len)
				{
					ans.push_back(s[temp - offset]);
				}
				else{
					break;
				}
				if (temp < len)
				{
					ans.push_back(s[temp]);
				}
				else {
					break;
				}
				temp = temp + dist_offset;
			}
		}
		// update pos pointing to the first character of the next line
		++pos;
		// if the next loop is the last line, clear offset; else update offset
		if (i == 2)
		{
			offset = 0;
		}
		else
		{
			offset = 2 * (numRows -i + 1);
		}
	}
	return ans;
}
