int romanToInt(string s) {
	int len = s.length();
	int indexLen = len - 1;
	int ans = 0;
	char temp;
	for (int i = 0; i < len; ++i)
	{
		temp = s[i];
		if (temp == 'I')
		{
			if (i < indexLen)
			{
				if (s[i + 1] == 'V')
				{
					ans += 4;
					++i;
				}
				else if (s[i + 1] == 'X')
				{
					ans += 9;
					++i;
				}
				else
				{
					ans += 1;
				}
			}
			else if (i == indexLen)
			{
				ans += 1;
			}
		}
		if (temp == 'V')
		{
			ans += 5;
		}
		if (temp == 'X')
		{
			if (i < indexLen)
			{
				if (s[i + 1] == 'L')
				{
					ans += 40;
					++i;
				}
				else if (s[i + 1] == 'C')
				{
					ans += 90;
					++i;
				}
				else
				{
					ans += 10;
				}
			}
			else if (i == indexLen)
			{
				ans += 10;
			}
		}
		if (temp == 'L')
		{
			ans += 50;
		}
		if (temp == 'C')
		{
			if (i < indexLen)
			{
				if (s[i + 1] == 'D')
				{
					ans += 400;
					++i;
				}
				else if (s[i + 1] == 'M')
				{
					ans += 900;
					++i;
				}
				else
				{
					ans += 100;
				}
			}
			else if (i == indexLen)
			{
				ans += 100;
			}
		}
		if (temp == 'D')
		{
			ans += 500;
		}
		if (temp == 'M')
		{
			ans += 1000;
		}
	}
	return ans;
}
