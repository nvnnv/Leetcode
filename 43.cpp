// 28ms 10.9MB
string multiply(string num1, string num2) {
	if (num1 == "" || num2 == "") return "";
	if (num1 == "0" || num2 == "0") return "0";
	if (num1 == "1") return num2;
	if (num2 == "1") return num1;

	int len1 = num1.size();
	int len2 = num2.size();
	string ans[2] = {"",""};

	int m = 0;
	for (int i = len1-1; i >=0; --i, ++m)
	{
		int temp1 = num1[i] - 48;
		int temp_mul = 0;
		string temp_str1 = "";
		string temp_str2 = "";
		temp_mul = temp1 * (num2[len2-1] -48);
		temp_str1 += temp_mul % 10 + 48;
		temp_str1 += temp_mul / 10 + 48;
		for (int j = len2-2; j >=0; --j)
		{
			int temp2 = num2[j] - 48;
			temp_mul = temp1 * temp2;
			temp_str2 += temp_mul % 10 + 48;
			temp_str2 += temp_mul / 10 + 48;

			//dislocation addition
			int t1 = temp_str1[temp_str1.size()-1] - 48 + temp_str2[0] - 48;
			int t2 = temp_str2[1] - 48 +t1/10;
			temp_str1.pop_back();
			temp_str1 += (t1%10 +48);
			temp_str1 += (t2 % 10 + 48);
			temp_str2 = "";
		}
		// temp_str1 == the result of subequation
		if (ans[1] == "")
		{
			ans[1] = temp_str1;
			temp_str1 = "";
		}
		else {
			ans[0] = temp_str1;
			temp_str1 = "";
			temp_str1 += ans[1].substr(0, m);
			int factor = 0;
			for (int k = m; k < ans[1].size(); ++k)
			{
				int t = ans[0][k - m]-48+ans[1][k]-48 + factor;
				factor = 0;
				if (t / 10)
				{
					factor = 1;
				}
				temp_str1 += (t % 10 + 48);
			}
			int l0 = ans[0].size();
			int l1 = ans[1].size();
			if (l0 > l1-m)
			{
				temp_str1 += (factor ? ans[0][l0 - 1] + 1 : ans[0][l0 - 1]);
			}
			else
			{
				temp_str1 += (factor ? "1" : "");
			}

			ans[1] = temp_str1;
		}
	}
    	if (ans[1][ans[1].size() - 1] == '0')
	{
		ans[0] = ans[1].substr(0, ans[1].size() - 1);
		reverse(ans[0].begin(), ans[0].end());
		return ans[0];
	}
	else
	{
		reverse(ans[1].begin(), ans[1].end());
		return ans[1];
	}
    }
