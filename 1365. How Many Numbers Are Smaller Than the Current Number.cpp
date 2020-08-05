vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> x;
    int t[101];
    memset(t, 0, sizeof(int) * 101);
    for (auto i : nums)
    {
        t[i]++;
    }
    int j = 0;
    for (int i = 0; i < 101; ++i)
    {
        if (t[i] > 0)
        {
            int k = j;
            j += t[i];
            t[i] = k;
        }
    }
    for (auto i : nums)
    {
        x.push_back(t[i]);
    }
    return x;
}
