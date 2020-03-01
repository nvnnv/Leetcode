// 4ms 8.8MB
void didid(vector<string>& ans, int layer, string& sub_ans, string& digits, string mapp[])
{
	if (layer >= digits.size())
	{
		ans.push_back(sub_ans);
		return;
	}
	auto s = mapp[digits[layer]-49];
	for (auto c : s)
	{
		sub_ans.push_back(c);
		didid(ans, layer + 1, sub_ans, digits, mapp);
		sub_ans.pop_back();
	}
}
vector<string> letterCombinations(string digits) {
	vector<string> ans;
	if (digits == "")
	{
		return ans;
	}
	string mapp[9] = { "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	string s = "";
	didid(ans, 0, s, digits, mapp);
	int i = 0;
	return ans;
}
