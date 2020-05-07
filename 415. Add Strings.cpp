string addStrings(string num1, string num2) {
    int lenNum1 = num1.size();
    int lenNum2 = num2.size();
    int carry = 0;
    int j = lenNum2 - 1;;
    int k = lenNum1 > lenNum2 ? lenNum1 - 1 : lenNum2 - 1;
    auto& ansStr = lenNum1 > lenNum2 ? num1 : num2;
    // 先不考虑前边有0
    for (int i = lenNum1-1; i >=0; --i)
    {
        int temp = num1[i]-48 + num2[j--]-48 + carry;
        if (temp >= 10)
        {
            carry = 1;
            ansStr[k] = temp % 10 + 48;
        }
        else
        {
            carry = 0;
            ansStr[k] = temp % 10 +48;
        }
        --k;
        if (j < 0) break;
    }
    if (lenNum1 > lenNum2)
    {
        j = lenNum1 - lenNum2 - 1;
        while (j >=0)
        {
            int temp = num1[j]-48 + carry;
            if (temp >= 10)
            {
                carry = 1;
                ansStr[j] = temp % 10 + 48;
            }
            else
            {
                carry = 0;
                ansStr[j] = temp % 10 + 48;
            }
            --j;
        }
    }
    if (lenNum1 < lenNum2)
    {
        j = lenNum2 - lenNum1 - 1;
        while (j >= 0)
        {
            int temp = num2[j]-48 + carry;
            if (temp >= 10)
            {
                carry = 1;
                ansStr[j] = temp % 10 + 48;
            }
            else
            {
                carry = 0;
                ansStr[j] = temp % 10 + 48;
            }
            --j;
        }
    } 
    return carry ? "1" + ansStr : ansStr;
}
