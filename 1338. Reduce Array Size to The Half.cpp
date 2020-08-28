int minSetSize(vector<int>& arr) {
    map<int, int> arr_map;
    for (auto i : arr)
    {
        arr_map[i]++;
    }
    int len = arr.size();
    int x = 0;
    int t = 0;
    vector<pair<int, int>> v;
    for (auto& p : arr_map)
    {
        v.push_back(p);
    }
    sort(v.begin(), v.end(), cmp);
    while (!v.empty())
    {
        t += v.back().second;
        v.pop_back();
        ++x;
        if (t >= (len / 2)) return x;
    }
    return x;
}
int cmp(pair<int, int>& i, pair<int, int>& j)
{
    return i.second < j.second;
}
