int lengthOfLongestSubstring(string s) {
	map<char, int> oMap;  // repeated elements map(char : the position in the susequence)
	int ans = 0;    
	int j = 0;  // loop index
	int temp = 0; // temply optimal answer
	char chPrevious = 0; // previous loop-value:i
	int t = 0;   // loop index+1
	int bIndex = 0; // the beginning position of temply optimal sequence
	for (char i: s)
	{
		t = j + 1;
		if (oMap[i] == 0)
		{// if not repeat, temp+1 
				++temp;
				oMap[i] = t;
		}
		else { // if finding the current element has repeated, update ans and run the if-struct below
			ans = temp > ans ? temp : ans;
			if (i == chPrevious)
			{// if the current element is repeated continously more than one time, reset temp and oMap
				temp = 1;
				oMap.clear();
				oMap[i] = t;
				bIndex = t;
			}
			else { // if not, update bIndex and calculate temp again
				bIndex = bIndex > oMap[i] ? bIndex : oMap[i];
				temp = t - bIndex;
				oMap[i] = t;
			}
		}
		chPrevious = i;
		++j;
	}
	ans = temp > ans ? temp : ans;
	return ans;
}
