#include <iostream>
#include <vector>

using namespace std;

void binarySearch(vector<int>& nums, int& target, int& beginIndex, int& endIndex)
{
	int i = 0;
	i = beginIndex + endIndex;
	i = i / 2;
	int j = nums[i];
	if (j > target)
	{
		endIndex = i - 1;
	}
	else if (j < target)
	{
		beginIndex = i + 1;
	}
	else
	{
		beginIndex = i;
		endIndex = i;
	}
}

// thinking about indexout of bounds any time!
int search(vector<int>& nums, int target) {
	if (nums.size() == 0) return -1;

	int firstNum = nums[0];
	int beginIndex = 1;
	int endIndex = nums.size() - 1;
	// find out the beginning of the second sequence -> FirstNum_SecSequence
	int FirstNum_SecSequence = beginIndex;
	int i = 0;
	int j = 0;
	while (beginIndex < endIndex)
	{
		i = beginIndex + endIndex;
		i = i / 2;
		j = nums[i];
		if (j < firstNum)
		{
			endIndex = i - 1;
			if (nums[endIndex] > j)
			{
				FirstNum_SecSequence = i;
				break;
			}
		}
		else
		{
			beginIndex = i + 1;
			if (nums[beginIndex] < j)
			{
				FirstNum_SecSequence = beginIndex;
				break;
			}
		}
	}
	//cout << FirstNum_SecSequence << endl;

	// two binary searches
	beginIndex = 0;
	endIndex = FirstNum_SecSequence - 1;
	while (beginIndex < endIndex)
	{
		binarySearch(nums, target, beginIndex, endIndex);
	}
	if (nums[beginIndex] == target)
	{
		return beginIndex;
	}

	beginIndex = FirstNum_SecSequence;
	endIndex = nums.size() - 1;
	while (beginIndex < endIndex)
	{
		binarySearch(nums, target, beginIndex, endIndex);
	}
	if (nums[endIndex] == target)
	{
		return endIndex;
	}
	return -1;
}

int main()
{
	vector<int> x = {3,5,1};
	cout << search(x, 1) << endl;
}
