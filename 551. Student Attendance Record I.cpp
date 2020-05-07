bool checkRecord(string s) {
    int len_s = s.size();
    int A = 0;
    for (int i =0;i<len_s;++i)
    {
        char c = s[i];
        if (c == 'A')
        {
            ++A;
            if (A > 1) return false;
        }
        if (c == 'L')
        {
            int k = i+1;
            while (s[k] == 'L') ++k;
            if (k-i > 2) return false;
            i = k - 1;
        }
    }
    return true;
}
