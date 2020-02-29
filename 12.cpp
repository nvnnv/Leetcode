// 16ms, 8.4MB
const int NUM = 13;
const int VAL[NUM] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
const string KEY[NUM] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
int doMax(int num)
{
	for (int i = NUM - 1; i >= 0; --i)
	{
		if (num >= VAL[i])
		{
			return i;
		}
	}
	return -1;
}
string intToRoman(int num) {
	if (num <= 0 || num > 3999) return "";

	int pos = 0;
	string ans;
	while (num > 0)
	{
		pos = doMax(num);
		num -= VAL[pos];
		ans.append(KEY[pos]);
	}
	return ans;
}
