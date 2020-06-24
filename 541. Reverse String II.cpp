string reverseStr(string s, int k) {
    int i = 0;
    int j = 1;
    int len_s = s.size();
    for (j; j < len_s; j += 2 * k)
    {
        int a = j - 1;
        int b = a + k-1;
        if (b >= len_s) b = len_s-1;
        // reverse()  is left-close and right-open;
         reverse(s.begin()+a,  s.begin()+b+1);
    }
    return s;
}
