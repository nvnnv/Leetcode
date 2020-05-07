string addBinary(string a, string b) {
    int a_end = a.size() - 1;
    int b_end = b.size() - 1;
    int carry = 0;
    string pix = "";
    string& ans = a_end > b_end ? a : b;
    int& ans_end = a_end > b_end ? a_end : b_end;
    while (true)
    {
        int temp = a[a_end]-48 + b[b_end]-48 + carry;
        if (temp > 1)
        {
            carry = 1;
            ans[ans_end] = temp +48 -2;
        }
        else
        {
            carry = 0;
            ans[ans_end] = temp + 48;
        }
        --a_end;
        --b_end;
        if (b_end < 0)
        {
            while (a_end >= 0)
            {
                temp = a[a_end]-48 + carry;
                if (temp == 2)
                {
                    carry = 1;
                    ans[ans_end] = '0';
                }
                else
                {
                    carry = 0;
                    ans[ans_end] = temp + 48;
                }
                --a_end;
            }
            break;
        }
        if (a_end < 0)
        {
            while (b_end >= 0)
            {
                temp = b[b_end]-48 + carry;
                if (temp == 2)
                {
                    carry = 1;
                    ans[ans_end] = '0';
                }
                else
                {
                    carry = 0;
                    ans[ans_end] = temp + 48;
                }
                --b_end;
            }
            break;
        }
    }
    if (carry) pix = '1';
    return pix + ans;
}
