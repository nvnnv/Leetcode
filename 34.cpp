/* 16ms */
/*
	Contantly seek toward left. On the other hand, constantly seek toward right.
	However, these two actions are exclusive.
	For left subsequences, we are able to find out the lower limit A, for right subsequences, the upper limit B is made.
	Consequently, {A,B} is just the answer.
	Para intro:
	res: answer, size=2；
	direction: direction=0 seek towrad left and right; direction=-1 only seek toward left; direction=1 only seek toward right；

	向左找下限A，向右找上限B，{A,B}就是答案列表。
	参数说明：
	res: 结果数组，长度为2；
	direction： direction=0 即向左又向右找；direction=-1 只能向左；direction=1 只能向右；
*/
void findMinOrMaxIndexWWithSame(vector<int>& nums, int indexBegin, int indexEnd, int target, vector<int>& res, int direction)
{
	if (res.size() < 2) return;
	int mid = 0;
	int temp = 0;
	while (indexBegin <= indexEnd)
	{
		mid = (indexBegin + indexEnd) / 2;
		temp = nums[mid];
		if (temp > target)
		{
			indexEnd = mid - 1;
		}
		else if (temp < target)
		{
			indexBegin = mid + 1;
		}
		else
		{
			if (temp == target)
			{
				res[0] = res[0] == -1 ? mid : min(mid, res[0]);
				if(direction < 1) findMinOrMaxIndexWWithSame(nums, 0, mid - 1, target, res, -1);
				res[1] = res[1] == -1 ? mid : max(mid, res[1]);
				if(direction > -1) findMinOrMaxIndexWWithSame(nums, mid + 1, nums.size() - 1, target, res, 1);
				break;
			}
		}
	}
}
vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> ans = { -1, -1 };
	int len = nums.size();
	if (len == 0)
	{
		return ans;
	}
	// binary search
	findMinOrMaxIndexWWithSame(nums, 0, len - 1, target, ans, 0);
	return ans;
}
