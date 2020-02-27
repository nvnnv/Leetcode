// 8ms 8.5mb it should be optimized. 
int myAtoi(string str) {
	if (str == "") return 0;
	const int MAX = INT_MAX / 10;
	int ans = 0;
	int flag = 0;
	int _signed = 1; // default positive number
	for (auto c : str)
	{
		if (c == ' ' && flag == 0) continue;
		if (flag == 0)
		{ // judge if there exist +/-
			flag = 1;
			if (c == '-')
			{
				_signed = -1;
				continue;
			}
			if (c == '+') continue;
		}
		if (c == '0' && flag == 1) continue; // ignore leading '0's
		if (c < 48 || c > 57) break; // end up
		// judge overflow
		if (fabs(ans) > MAX)
		{
			if (_signed < 0) return INT_MIN;
			else return INT_MAX;
		}
		if (fabs(ans) == MAX)
		{
			if (_signed > 0 && c > 54)
			{
				if (_signed < 0) return INT_MIN;
				else return INT_MAX;
			}
			if (_signed < 0 && c > 56)
			{
				if (_signed < 0) return INT_MIN;
				else return INT_MAX;
			}
		}
		// judge overflow
		ans = ans * 10 + (_signed * (c - 48)); // adding '()' is to prevent overflow of adding  
		flag = 2; // there is an issue: repeated execute ---> how to amend it?
	}
	return ans;
}
