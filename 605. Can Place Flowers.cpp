bool canPlaceFlowers(vector<int>& flowerbed, int n) {
	int len = flowerbed.size();
	if (n == 0) return true;
	if (len == 1)
	{
		if (n == 1 && flowerbed[0] == 0)return true;
		else return false;
	}
  /* think about these situations below
    1: 000001
    2: 1000001
    3: 100000
    4: 000000
    the array given in the question have to be composed of these subsequences above.
    so, calculate the maximum of all subsequences and add them up.
  */
	int ans = 0;
	int f = 0, e = 0;
	if (flowerbed[0] == 0)
	{
		f = -2;
	}
	for (int i = 1; i < len; ++i)
	{
		if (flowerbed[i] == 1)
		{
			e = i;
			ans += (e - f - 2) / 2;
			f = i;
		}
	}

	if (flowerbed[len-1] == 0)
	{
		if (f == -2) e = len + 1;
		else e = len - 1 - f;
		ans += e/ 2;
	}
	return ans >= n ? true : false;
}
