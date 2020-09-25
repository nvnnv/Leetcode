int minAddToMakeValid(string S) {
    int l = 0;
    int r = 0;
    for (int i = 0; i < S.size(); ++i)
    {
        if (S[i] == '(')
        {
            ++l;
        }
        else
        {
            if (l) --l;
            else ++r;
        }
    }
    return l + r;
}
