/*
  1 2 3 4
  3 4 5 6
  4 5 6 7
  5 6 7 8
  solution: seperate the matrix into several rims like this below
  first rim:
  1 2 3 4
  3     6
  4     7
  5 6 7 8
  second rim:
  4 5
  5 6
  each rim is independent
  For first rim is changed like this below
  5 4 3 1
  6     2
  7     3
  8 7 6 4
  and the second situation is same
*/
void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	if (n <= 1)
	{
		return;
	}
	int loop_n = n / 2; 
	int jump_n = n - 1; // substract 2 each loop
	int i = 0; // row
	int temp1,temp2;
	bool straight_down = true;
	while (loop_n--)
	{
		int j_offset_2 = 0;
		int j_offset_1 = 0;
		int i_offset = 0;
		for (int j = i; j < n-i-1; ++j)
		{
			// first
			temp1 = matrix[i+i_offset][j + jump_n-j_offset_1];
			matrix[i+i_offset][j + jump_n-j_offset_1] = matrix[i][j];
			// second
			temp2 = matrix[i + jump_n][j + jump_n-j_offset_2];
			matrix[i + jump_n][j + jump_n-j_offset_2] = temp1;
			// third
			temp1 = matrix[i + jump_n-i_offset][j-i_offset];
			matrix[i + jump_n-i_offset][j-i_offset] = temp2;
			// fourth
			matrix[i][j] = temp1;

			++i_offset;
			j_offset_2 += 2;
			++j_offset_1;
		}
		++i;
		jump_n -= 2;
	}
}
