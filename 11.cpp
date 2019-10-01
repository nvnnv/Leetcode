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

/* 16ms constantly throw the smaller number out and reduce the range */
int maxArea(vector<int>& height) {
	int i = 0;
	int j = height.size()-1;
	int k = 0;
	int curVolume = 0;
	int res = 0;
	while (i < j)
	{
		curVolume = (j - i) * min(height[i], height[j]);
		res = curVolume > res ? curVolume : res;
	    k = height[i] > height[j] ? --j : ++i;
	}
	return res;
}
