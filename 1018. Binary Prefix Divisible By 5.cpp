vector<bool> prefixesDivBy5(vector<int>& A) {
	int n = A.size();
	vector<bool> ans;
	int flag[4];
	flag[1] = 2; flag[2] = 4; flag[3] = 8; flag[0] = 6;
	const int factor = 4;
	int iSum= 0;
	for (int i = 0; i < n; ++i)
	{
        iSum = (iSum*2 + A[i])%10;
		ans.push_back(iSum % 5 ? false : true);
	}
	return ans;
}
