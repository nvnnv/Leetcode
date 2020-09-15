bool cmp2(pair<int, vector<int>>& x, pair<int, vector<int>>& y)
{
    int i = 0;
    while (i < x.second.size())
    {
        if (x.second[i] == y.second[i])
        {
            ++i;
        }
        else
        {
            return x.second[i] > y.second[i];
        }
    }
    return x.first < y.first;
}


string rankTeams(vector<string>& votes) {
    map<int, vector<int>> rank;
    for (auto& s : votes)
    {
        for (int i =0; i<s.size();++i)
        {
            if (rank.count(s[i]) == 0)
            {
                vector<int> x(s.size(), 0);
                rank[s[i]] = x;
            }
            rank[s[i]][i]++;
        }
    }
    vector<pair<int, vector<int>>> x;
    for (auto& p : rank)
    {
        x.push_back(p);
    }
    sort(x.begin(), x.end(), cmp2);
    string res;
    for (auto& p : x)
    {
        res.push_back(p.first);
    }
    return res;
}
