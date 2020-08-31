vector<string> commonChars(vector<string>& A) {

    vector<int> a(26, 0);
    for (auto c : A.back())
    {
        a[c - 'a']++;
    }
    A.pop_back();
    for (auto& v : A)
    {
        vector<int> b(26, 0);
        for (auto c : v)
        {
            b[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i)
        {
            a[i] = min(a[i], b[i]);
        }
    }
    vector<string> x;
    for (int i = 0; i < 26; ++i)
    {
        while(a[i])
        {
            string s = "";
            s.push_back(i + 'a');
            x.push_back(s);
            a[i]--;
        }
    }
    return x;
}
