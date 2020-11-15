int tryHe(vector<int>& a)
{
    int s = 0;
    for (auto i : a)
    {
        s = s * 10 + i;
    }
    return s;
}
unordered_map<int, int> fp;
int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    int ssss = tryHe(needs);
    if (ssss == 0) return 0;
    if (fp.count(ssss)) return fp[ssss];
    int n = needs.size();
    int s = special.size();
    int p = 0;
    for (int i = 0; i < n; ++i)
    {
        p += needs[i] * price[i];
    }
    for (int i = 0; i < s; ++i)
    {
        int j = 0;
        vector<int> seed = needs;
        for (j; j < n; ++j)
        {
            seed[j] = needs[j] - special[i][j];
            if (seed[j] < 0) break;
        }
        if (j == n)
        {
            p = min(p, special[i][j] + shoppingOffers(price, special, seed));
        }
    }
    fp[ssss] = p;
    return p;
}
