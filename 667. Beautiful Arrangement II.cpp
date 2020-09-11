vector<int> constructArray(int n, int k) {

    int left = 1 + k;
    vector<int> ans = {1};
    int condition = 0;
    int ma = 0;
    for (int i = k; i > 0; --i)
    {
        if (condition % 2)
        {
            int t = ans.back() - i;
            ans.push_back(t);
        }
        else
        {
            int t = ans.back() + i;
            ans.push_back(t);
            ma = max(ma, t);
        }
        condition++;
    }
    for (int i = ma + 1; i <= n; ++i) ans.push_back(i);
    return ans;
}
