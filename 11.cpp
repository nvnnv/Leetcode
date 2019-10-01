/* 2448ms */
int maxArea(vector<int>& height) {
	int len = height.size();
	int res = 0;
	for (int i = 0; i < len; ++i)
	{
		for (int j = i + 1; j < len; ++j)
		{
			res = max(res, (j - i) * min(height[i], height[j]));
		}
	}
	return res;
}

/*  */
