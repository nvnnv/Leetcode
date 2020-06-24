static bool cmp (const pair<string, string>& x, const pair<string, string>& y)
{
    return x.second > y.second;
}
vector<vector<string>> findDuplicate(vector<string>& paths) {
    vector<pair<string, string>> ans;
    for (auto& s : paths)
    {
        string path;
        int i = 0;
        while (s[i] != ' ') ++i;
        path = s.substr(0, i);
        ++i;
        for (int j = i; j < s.size();)
        {
            if (s[j] == '(')
            {
                string name = s.substr(i, j-i);
                string content = "";
                ++j;
                while (s[j] != ')')
                {
                    content.push_back(s[j]);
                    ++j;
                }
                ans.push_back(make_pair(path + "/" + name, content));
                ++j;
                i = j + 1;
            }
            else
            {
                ++j;
            }
        }
    }
   sort(ans.begin(), ans.end(), cmp);
   vector<vector<string>> xxoo;
   auto& base = ans[0];
   vector<string> xo;
    for (auto& p : ans)
    {
        if (p.second == base.second)
        {
            xo.push_back(p.first);
        }
        else
        {
            base = p;
            if(xo.size()> 1) xxoo.push_back(xo);
            xo.clear();
            xo.push_back(p.first);
        }
    }
    if(xo.size()> 1) xxoo.push_back(xo);
    return xxoo;
}
