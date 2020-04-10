bool validMountainArray(vector<int>& A) {
	int n = A.size();
	if (n < 3) return false;
	bool f = false;
	bool f1 = false;
	for (int i = 1; i < n; ++i)
	{
		if (A[i] < A[i - 1])
		{
			if(f1) f = true;
			if (!f1) return false;
		}
		if (A[i] > A[i - 1])
		{
			if(f) return false;
			if (!f) f1 = true;
		}
		if (A[i] == A[i - 1]) return false;
	}
	return f&&f1;
}
