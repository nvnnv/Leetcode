/* this answer contains the template of quicksort algorithm written by myself. 代码中包含我自己写的快速排序模板 */
/* 12ms */
/*
	quicksort algorithm is made by recursion. 递归实现快速排序
*/
void quickSort(vector<int>& nums, int posBegin, int posEnd)
{
	if (posEnd <= posBegin)
	{
		return;
	}
	int base = nums[posBegin];
	int i = posBegin, j = posEnd;
	while (i != j)
	{
		while (true)
		{
			if (nums[j] < base)
			{
				swap(nums[i], nums[j]);
				++i;
				break;
			}
			if (j > i)
			{
				--j;
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			if (nums[i] > base)
			{
				swap(nums[i], nums[j]);
				--j;
				break;
			}
			if (i < j)
			{
				++i;
			}
			else
			{
				break;
			}
		}
	}
	quickSort(nums, posBegin, i - 1);
	quickSort(nums, i + 1, posEnd);
}

void nextPermutation(vector<int>& nums) {
	/* from right to left, seek two numbers(ai, aj, j-i=1) required that the relationship aj<ai occurs 
	for the first time in the sequence a. After that, from right to left, seek the number ak(ak>ai, k>=j&k<list.size) */
	/* swap ai ak, make the subsequence after index i be reordered by asc. */
	/* if not find out ai and aj, current sequence is just the last sequence in the pernumtation */

	// seeking ai aj ak
	bool F = false;
	int len = nums.size();
	if (len == 0 || len == 1)
	{
		return;
	}
	int i = len - 2, j = len - 1;
	for (i, j; i >= 0; --i, --j)
	{
		if (nums[i] < nums[j])
		{
			F = true;
			break;
		}
	}
	if (F == true)
	{
		int k = len - 1;
		for (k; k >= j; --k)
		{
			// swap ai ak
			if (nums[k] > nums[i])
			{
				swap(nums[i], nums[k]);
				break;
			}
		}
	}
	else
	{
		i = -1;
	}
	// reorder without the help of the extraly continuous space for the subsequence after aj
	quickSort(nums, i + 1, nums.size() - 1);
}
