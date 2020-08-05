vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vector<bool> bv;
    for (auto& s : queries)
    {
        int i = 0;
        int j = 0;
        for (auto c : s)
        {
            if (c == pattern[i])
            {
                ++i;
                continue;
            }
            if (c >= 65 && c <= 90)++j;
        }
        if (i == pattern.size() && j == 0)
            bv.push_back(true);
        else
            bv.push_back(false);
    }
    return bv;
}
