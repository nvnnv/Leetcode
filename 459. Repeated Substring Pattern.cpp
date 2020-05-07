bool repeatedSubstringPattern(string s) {
    int base = 2;
    int len_s = s.size();
    if (s == "" || len_s == 1) return false;
    while (true)
    {
        if (len_s % base == 0)
        {
            int temp = len_s / base;
            int L = 0;
            int ML = 0;
            for (int i = 1; i < base; ++i)
            {
                L = 0;
                ML = L + temp * i;
                int temp1 = temp;
                while (temp1)
                {
                    if (s[L++] != s[ML++])
                    {
                        goto bbb;
                    }
                    --temp1;
                }
            }
            return true;
        }
        bbb: ++base;
        if (base > len_s)
        {
            break;
        }
    }
    return false;
}
