bool startWith(string& aim, string& match)
{
    int i = 0;
    while (i < match.size() && i <= aim.size())
    {
        if (match[i] == aim[i]) ++i;
        else break;
    }
    return i == match.size();
}
vector<string> removeSubfolders(vector<string>& folder) {
    sort(folder.begin(), folder.end());

   set<string> ans;
    auto& base_match = folder[0];
    for (int i =1;i<folder.size(); ++i)
    {
        auto temp = base_match + "/";
        if (startWith(folder[i], temp) == true)
        {
            ans.insert(base_match);
        }
        else
        {
            ans.insert(base_match);
            base_match = folder[i];
        }
    }
    ans.insert(base_match);
    vector<string> a;
    for (auto& s : ans)
    {
        a.push_back(s);
    }
    return a;
}
