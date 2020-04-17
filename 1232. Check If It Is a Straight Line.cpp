bool checkStraightLine(vector<vector<int>>& coordinates) {
	int n = coordinates.size();
	if (n < 3) return true;

	if ((coordinates[0][0] - coordinates[1][0]) != 0)
	{
		int k = (coordinates[0][1] - coordinates[1][1]) / (coordinates[0][0] - coordinates[1][0]);
		int b = coordinates[0][1] - k * coordinates[0][0];
		for (int i = 2; i < n; ++i)
		{
			if ((k * coordinates[i][0] + b) == coordinates[i][1]) continue;
			else return false;
		}
	}
	else
	{
		for (int i = 2; i < n; ++i)
		{
			if (coordinates[i][0] == coordinates[i-1][0]) continue;
			else return false;
		}
	}
	return true;
}
