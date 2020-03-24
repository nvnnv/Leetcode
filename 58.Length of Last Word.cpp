int lengthOfLastWord(string s) {
	if (s == " " || s == "") return 0;
	int len = s.size()-1;
	int pos = 0;
	int ans = 0;
	bool xx = false;
	while (pos <= len)
	{
		if (s[pos] == ' ')
		{
			xx = true;
		}
		else if(xx){
			xx = false;
			ans = 0;
		}
		if (xx != true)
		{
			++ans;
		}
		++pos;
	}
	return ans;
}
