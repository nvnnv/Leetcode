bool checkIfExist(vector<int>& arr) {
	int n = arr.size();
	if (n < 2) return false;

	sort(arr.begin(), arr.end());
	for (int i = 0; i < n;++i)
	{
		int temp = arr[i]*2;
		int temp1 = 0;
		int L = 0;
		int R = 0;
		if (temp > 0)
		{
			L = i + 1;
			R = n - 1;
		}
		else
		{
			L = 0;
			R = i - 1;
		}
		while (L <= R)
		{
			temp1 = (R + L) / 2;
			if (arr[temp1] == temp)
			{
				return true;
			}
			if (arr[temp1] > temp)
			{
				R = temp1 - 1;
			}
			if (arr[temp1] < temp)
			{
				L = temp1 + 1;
			}
		}
	}
	return false;
}
