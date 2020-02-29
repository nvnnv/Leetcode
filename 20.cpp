// 4ms 8.8MB
bool isValid(string s) {
	int len = s.size();
	if (s == "") return true;
	if (len % 2 == 1) return false;

	stack<int> t;
	char c = 0;
	for (int i = 0; i < len; ++i)
	{
		c = s[i];
		if (c == 40 || c == 123 || c == 91)
		{
			t.push(c);
		}
		else if (c == 41 || c == 125 || c == 93)
		{
			if (t.empty() == true)
			{
				return false;
			}
			else if (t.top() == c -1 || t.top() == c-2)
			{
				t.pop();
			}
			else {
				return false;
			}
		}
	}
	if (t.empty() != true) return false;
	return true;
}
