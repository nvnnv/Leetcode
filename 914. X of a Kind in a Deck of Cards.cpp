// 32ms 
inline int max_common_divisor(int a, int b)
{
	return a % b && b != 1 ? max_common_divisor(b, a % b) : b;
}
    
bool hasGroupsSizeX(vector<int>& deck) {
	int n = deck.size();
	if (n == 0 || n == 1) return false;
	sort(deck.begin(), deck.end());
	// exp
	if (deck[n - 1] != deck[n - 2]) return false;
	if (deck[0] != deck[1]) return false;

	int num = 1;
	int num1 = 0;
	for (int i = 0; i < n-1; ++i)
	{
		while (deck[i] == deck[i + 1])
		{
			++i;
			++num;
			if (i >= n-1) break;
		}
		if (num <= 1) return false;
		if (num1 != 0)
		{
			if (max_common_divisor(max(num,num1),min(num,num1))==1) return false;
		}
		num1 = num;
		num = 1;
	}
	return true;
}

// 20ms
inline int max_common_divisor(int a, int b)
{
	return a % b && b != 1 ? max_common_divisor(b, a % b) : b;
}
    
bool hasGroupsSizeX(vector<int>& deck) {
	int n = deck.size();
	if (n == 0 || n == 1) return false;
	
	unordered_map<int, int> flag;
	for (auto i : deck)
	{
		++flag[i];
	}
	int prev = flag.begin()->second;
	for (auto i : flag)
	{
		prev = max_common_divisor(max(prev, i.second), min(prev, i.second));
		if (prev == 1)
		{
			return false;
		}
	}
	return true;
}

