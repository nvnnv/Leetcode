vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> ans;
	int column_n = matrix.size();
	if (column_n == 0)
	{
		return ans;
	}
	if (column_n==1)
	{
		for (auto i : matrix[0])
		{
			ans.push_back(i);
		}
		return ans;
	}
	int n = column_n / 2 + column_n % 2;
	int row_n = matrix[0].size();
	if (row_n == 1)
	{
		for (int i = 0; i < column_n; ++i)
		{
			ans.push_back(matrix[i][0]);
		}
		return ans;
	}
	int i = 0;
	while(true)
	{
		//1st
		for (int c1 = i; c1 <= row_n - 1 - i; ++c1)
		{
			ans.push_back(matrix[i][c1]);
		}
		//2nd
		for (int c2 = i+1; c2 < column_n-i-1; ++c2)
		{
			ans.push_back(matrix[c2][row_n - 1 - i]);
		}
		//3th
		if (column_n - i - 1 != i)
		{
			for (int c3 = row_n - i - 1; c3 >= i; --c3)
			{
				ans.push_back(matrix[column_n - i - 1][c3]);
			}
		}
		//4th
		if (row_n - i - 1 != i)
		{
			for (int c4 = column_n - i - 2; c4 >= i + 1; --c4)
			{
				ans.push_back(matrix[c4][i]);
			}
		}
		if ((column_n - i - 1 - i)<=1 || (row_n - i - 1 - i)<=1) break;
		++i;
	}
	return ans;
}
