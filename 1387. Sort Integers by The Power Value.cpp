bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
int stepsPower(int t)
{
    int s = 0;
    while(t != 1)
    {
        if (t % 2) t = t * 3 + 1;
        else t = t / 2;
        ++s;
    }
    return s;
}
int getKth(int lo, int hi, int k) {
    vector<pair<int, int>> v;
    for (int i = lo; i <= hi; ++i)
    {
        v.push_back(make_pair(i, stepsPower(i)));
    }
    sort(v.begin(), v.end(), cmp);
    return v[k - 1].first;
}
