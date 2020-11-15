stringstream sxs;
string decodeString(string s) {
    string f = "";
    int i = 0;
    int j = s.size() - 1;
    int x = 0;
    for (i = 0; i < s.size(); ++i)
    {
        if (s[i] > '0' && s[i]<= '9')
        {
            string num = "";
            while (s[i] != '[')
            {
                num += s[i]; ++i;
            }
            int a = 0;
            for (j=i; j < s.size(); ++j)
            {
                if (s[j] == '[') ++a;
                if (s[j] == ']') --a;
                if (a == 0) break;
            }
            string _s = decodeString(s.substr(i + 1, j - i-1));
            sxs.clear();
            sxs << num;
            int n;
            sxs >> n;
            string t = "";
            while (n--)
            {
                t+= _s;
            }
            f += t;
            i = j;
        }
        else
        {
            f += s[i];
        }
    }
    return f;
}
