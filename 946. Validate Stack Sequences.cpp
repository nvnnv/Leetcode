// 20ms
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	int len_pushed = pushed.size(), len_poped = popped.size();
	if (len_poped != len_pushed) return false;

	int j = 0;
	stack<int> temp_st;
	for (int i = 0; i < len_pushed; ++i)
	{
		temp_st.push(pushed[i]);
		while (!temp_st.empty() && j < len_poped && popped[j] == temp_st.top())
		{
			temp_st.pop();
			++j;
		}
	}
	return temp_st.empty();
}
// 36ms
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	int len_pushed = pushed.size(), len_poped = popped.size();
	if (len_pushed == 0 || len_poped == 0)
	{
		return true;
	}

	unordered_set<int> flag;
	int aim = popped[0];
	int x = 0;
	for (int i =len_pushed-1;i>=0;--i)
	{
		if (aim == pushed[i])
		{
			x = i;
			break;
		}
	}
	flag.insert(x);
	int i = 1;
	for (i; i < len_poped; ++i)
	{
		while (flag.count(x - 1)) --x;
		if (x-1>= 0 && popped[i] == pushed[x - 1])
		{
			flag.insert(x - 1);
			x = x - 1;
		}
		else
		{
			bool f = false;
			for (int j = x + 1; j < len_pushed; ++j)
			{
				if (flag.count(j)) continue;
				if (popped[i] == pushed[j])
				{
					flag.insert(j);
					x = j;
					f = true;
					break;
				}
			}
			if (!f) return false;
		}
	}
	return true;
}
