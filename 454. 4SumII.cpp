class Solution {
public:
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	vector<int> new_a;
	vector<int> new_b;
	for (int i : A)
	{
		for (int j : B)
		{
			new_a.push_back(i + j);
		}
	}
	for (int i : C)
	{
		for (int j : D)
		{
			new_b.push_back(i + j);
		}
	}

	unordered_map<int, pair<int,int>> flag;
	sort(new_b.begin(), new_b.end());
	int ans = 0;
	int len_b = new_b.size();
	for (int i : new_a)
	{
		if (flag.count(i))
		{
			++flag[i].second;
			continue;
		}
		ans = 0;
		int temp = 0 - i;
		int B = 0;
		int E = len_b - 1;
		while (B <=E)
		{
			int temp1 = (B + E) / 2;
			int temp2 = new_b[temp1];
			if (temp2 > temp)
			{
				E = temp1-1;
			}
			else if (temp2 < temp)
			{
				B = temp1+1;
			}
			else if (temp2 == temp)
			{
				++ans;
				for (int k = temp1 + 1; k < len_b; ++k)
				{
					if (temp2 == new_b[k]) ++ans;
					else break;
				}
				for (int k = temp1 - 1; k >=0; --k)
				{
					if (temp2 == new_b[k]) ++ans;
					else break;
				}
				flag.insert(make_pair(i,make_pair(ans, 1)));
				break;
			}
		}
	}
	ans = 0;
	for (auto i : flag)
	{
		ans += i.second.first*i.second.second;
	}
	return ans;
}
};
