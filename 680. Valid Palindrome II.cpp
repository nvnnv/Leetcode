// 188ms
bool validPalindrome(string s) {
    int L = 0;
    int R = s.size() - 1;
    int f = 0;
    int CL = 0;
    int CR = s.size() - 1;
    while (L <= R)
    {
        if (s[L] == s[R])
        {
            ++L;
            --R;
        }
        else
        {
            if (f > 1) return false;
            if (f == 1)
            {
                L = CL;
                R = CR-1;
                f++;
                continue;
            }
            f++;
            CL = L;
            CR = R;
            if (s[L + 1] == s[R])
            {
                ++L; continue;
            }
            else if (s[L] == s[R - 1])
            {
                --R; continue;
            }
            return false;
        }
    }
    return true;
}
