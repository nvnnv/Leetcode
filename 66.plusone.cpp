    vector<int> plusOne(vector<int>& digits) {
        	if (digits.size() == 0) return {};
	int temp = 0;
	for (int i = digits.size() - 1; i >= 0; --i)
	{
		temp = digits[i] + 1;
		if (temp == 10)
		{
			digits[i] = 0;
		}
		else {
			digits[i] = temp;
			break;
		}
	}

	if (temp == 10)
	{
		digits[0] = 0;
		digits.insert(digits.begin(), 1, 1);
	}
	return digits;
    }
