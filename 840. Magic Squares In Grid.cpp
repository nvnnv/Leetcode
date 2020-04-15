int numMagicSquaresInside(vector<vector<int>>& grid) {
	int w = grid[0].size();
	int l = grid.size();

	// must meet the situation '5' has to the center of the 3*3 matrix
	if (w < 3 || l < 3) return 0;
	int row = 0, row1=0;
	int column = 0, column1=0;
	int diagonal = 0, diagonal1 = 0;
	int ans = 0;
	int a1, a2, a3, a4, a5, a6, a7, a8, a9;
		for (int i = 0; i <= l - 3; ++i)
		{
			for (int j = 0; j <= w - 3; ++j)
			{
				if (grid[i + 1][j + 1] == 5)
				{
					a1 = grid[i][j]; a2 = grid[i][j + 1]; a3 = grid[i][j + 2]; a4 = grid[i + 1][j]; a5 = grid[i + 1][j + 1]; a6 = grid[i + 1][j + 2]; a7 = grid[i + 2][j]; a8 = grid[i + 2][j + 1]; a9 = grid[i + 2][j + 2];
					if ((a1 < 1 || a1 >9) || (a2 < 1 || a2 >9) || (a3 < 1 || a3 >9) || (a4 < 1 || a4 >9) || (a5 < 1 || a5 >9) || (a6 < 1 || a6 >9) || (a7 < 1 || a7 >9) || (a8 < 1 || a8 >9) || (a9 < 1 || a9 >9)) continue;
					if (a1 + a9 != 10) continue;
					if (a2 + a8 != 10) continue;
					if (a3 + a7 != 10) continue;
					if (a4 + a6 != 10) continue;
					if (a1 == a9) continue;
					if (a2 == a8) continue;
					if (a3 == a7) continue;
					if (a4 == a6) continue;

					if (a1 + a2 + a3 != 15) continue;
					if (a7 + a8 + a9 != 15) continue;
					if (a1 + a4 + a7 != 15) continue;
					if (a3 + a6 + a9 != 15) continue;
					++ans;
				}
			}
		}
		return ans;
}
