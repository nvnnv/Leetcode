bool cmp1(pair<int, int>& a, pair<int, int>& b)
{
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
    vector<pair<int, int>> filtered;
    for (auto& v : restaurants)
    {
        if (veganFriendly == 0)
        {
            if(v[3] <= maxPrice && v[4] <= maxDistance) filtered.push_back(make_pair(v[0], v[1]));
        }
        else
        {
            if (v[2] == veganFriendly && v[3] <= maxPrice && v[4] <= maxDistance)
            {
                filtered.push_back(make_pair(v[0], v[1]));
            }
        }
    }
    sort(filtered.begin(), filtered.end(), cmp1);
    vector<int> res;
    for (auto& p : filtered)
    {
        res.push_back(p.first);
    }
    return res;
}
