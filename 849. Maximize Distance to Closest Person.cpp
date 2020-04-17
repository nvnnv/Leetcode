int maxDistToClosest(vector<int>& seats) {
	int n = seats.size();
	// find  10000...01
	int b = 0;
	int max = 0;
	int temp = 0;
	int coun = 0;
	if (seats[0] == 1) b = 1;
	for (int i = 0; i < n; ++i)
	{
		if (seats[i] == 0)
		{
			++coun;
		}
		else
		{
			if (coun == 0) continue;
			else
			{
				if (b == 0) temp = coun;
				else temp = coun > 1 ? coun / 2 + coun % 2 : 1;
				if (max < temp) max = temp;
				coun = 0;
			}
			b = i;
		}
	}
	if (seats[n - 1] == 0)
	{
		temp = coun;
		max = max < temp ? temp : max;
	}
	return max;
}
