bool cmp3(pair<int, int>& x, pair<int, int>& y)
{
    if (x.second == y.second) return x.first < y.first;
    return x.second < y.second;
}

int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    unordered_map<int, int> a;
    for (auto i : arr)
    {
        a[i]++;
    }
    vector<pair<int, int>> x;
    for (auto& p : a)
    {
        x.push_back(make_pair(p.first, p.second));
    }
    sort(x.begin(), x.end(), cmp3);
    int i = 0;
    while (i < x.size() && k >= x[i].second)
    {
        k -= x[i].second;
        ++i;
    }
    return x.size() - i;
}
