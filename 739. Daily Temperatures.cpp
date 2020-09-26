vector<int> dailyTemperatures(vector<int>& T) {
    stack<pair<int, int>> cache;
    vector<int> x = {};
    int t = T.size() - 1;
    for (auto i = T.rbegin(); i != T.rend(); ++i)
    {
        while (!cache.empty())
        {
            if (*i < cache.top().first) break;
            cache.pop();
        }
        if (cache.empty()) x.push_back(0);
        else x.push_back(cache.top().second - t);
        cache.push(make_pair(*i, t)); --t;
    }
    reverse(x.begin(), x.end());
    return x;
}
