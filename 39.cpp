void subLoopRecursion(int beginIndex, vector<vector<int>>& ans, vector<int>& candi, int target, map<int, int>& timeMapper)
{
	if (target == 0)
	{
		return;
	}
	int temp = 0;
	int tempInner = 0;
	// outer loop checks each element from the index 'beginIndex' to the beginning
	for (int i = beginIndex; i >= 0; --i)
	{
		temp = candi[i];
		if (target < temp)
		{
			continue;
		}
		// seek all groups which each one includes the number 'temp' and the sum of all numbers in it is equel to 'target'
		tempInner = target - temp;
		vector<int> subAns;
		subAns.push_back(temp);
		if (tempInner <= temp)
		{
			if (tempInner == 0)
			{
				ans.push_back(subAns);
				continue;
			}
			if (timeMapper[tempInner] > 0)
			{
				subAns.push_back(tempInner);
				ans.push_back(subAns);
				subAns.pop_back();
			}
		}
		vector<vector<int>> subSubAns;
		// if tempInner == temp, skip it and proceed to do the next one
		if (tempInner == temp)
		{
			subLoopRecursion(i - 1, subSubAns, candi, tempInner, timeMapper);
		}
		else
		{
			subLoopRecursion(i, subSubAns, candi, tempInner, timeMapper);
		}
		/*
		cout << "-------" << endl;
		cout << "a: " << tempInner << endl;
		cout << "b: " << subSubAns.size() << endl;
		for (auto j = subSubAns.begin(); j != subSubAns.end(); ++j)
		{
			cout << "=== ";
			for (auto k = j->begin(); k != j->end(); ++k)
			{
				cout << *k << " ";
			}
			cout << endl;
		}
		*/
		for (auto j: subSubAns)
		{
			if (j.size() == 1)
			{
        // only the length of the list have to be beyond 2 because 'tempInner' must be split up
				continue;
			}
			subAns.insert(subAns.end(), j.begin(), j.end());
			ans.push_back(subAns);
			subAns.clear();
			subAns.push_back(temp);
		}
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> ans;
	int len = candidates.size();
	if (len == 0)
	{
		return ans;
	}
	// sort
	sort(candidates.begin(), candidates.end());
	map<int, int> intToCount;
	for (int i = 0; i < len; ++i)
	{
		++intToCount[candidates[i]];
	}
	subLoopRecursion(len-1, ans, candidates, target, intToCount);
	return ans;
}
