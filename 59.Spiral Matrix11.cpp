vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> ans;
	if (n == 0) return ans;
	if (n == 1) return{ {1} };
	int count = 1;
	int column_n = n;
	int row_n = n;
	for (int i = 0; i < n; ++i)
	{
		vector<int> subAns;
		for (int j = 0; j < n; ++j)
		{
			subAns.push_back(0);
		}
		ans.push_back(subAns);
	}
	int i = 0;
	while (true)
	{
		//1st
		for (int c1 = i; c1 <= row_n - 1 - i; ++c1)
		{
			ans[i][c1] = count++;
		}
		//2nd
		for (int c2 = i + 1; c2 < column_n - i - 1; ++c2)
		{
			ans[c2][row_n - 1 - i] = count++;
		}
		//3th
		if (column_n - i - 1 != i)
		{
			for (int c3 = row_n - i - 1; c3 >= i; --c3)
			{
				ans[column_n - i - 1][c3] = count++;
			}
		}
		//4th
		if (row_n - i - 1 != i)
		{
			for (int c4 = column_n - i - 2; c4 >= i + 1; --c4)
			{
				ans[c4][i] = count++;
			}
		}
		if ((column_n - i - 1 - i) <= 1 || (row_n - i - 1 - i) <= 1) break;
		++i;
	}
	return ans;
}
