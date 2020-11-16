int find(int x, unordered_map<int, int>& uf)
{
    if (!uf.count(x)) { uf[x] = x; return x; }
    if (x == uf[x]) return x;
    else
    {
        uf[x] = find(uf[x], uf);
        return uf[x];
    }
}
void uni(int x, int y, unordered_map<int, int>& uf)
{
    x = find(x, uf);
    y = find(y, uf);
    if (x != y) uf[y] = x;
}
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, string> names;
    unordered_map<string, int> accId;
    unordered_map<int, int> uf;
    int id = 0;
    for (auto& v : accounts)
    {
        for (int i = 2; i < v.size(); ++i)
        {
            if(!accId.count(v[i-1])) accId[v[i - 1]] = id++;
            if(!accId.count(v[i])) accId[v[i]] = id++;
            uni(accId[v[i]], accId[v[i-1]], uf);
            names[v[i]] = v[0];
        }
        if (!accId.count(v[1])) accId[v[1]] = id++;
        names[v[1]] = v[0];
    }
    vector<vector<string>> ans;
    unordered_map<int, int> index;
    int i = 0;
    for (auto& p : names)
    {
        int f = find(accId[p.first], uf);
        if (!index.count(f))
        {
            index[f] = i++;
            vector<string> s = { p.second };
            ans.push_back(s);
        }
        ans[index[f]].push_back(p.first);
    }
    for (auto& v : ans)
    {
        sort(v.begin() + 1, v.end());
    }
    return ans;
}
