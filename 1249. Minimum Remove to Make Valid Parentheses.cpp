string minRemoveToMakeValid(string s) {
    stack<pair<int, int>> L;
    stack<pair<int, int>> R;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            L.push(make_pair(s[i], i));
            continue;
        }
        if (s[i] == ')')
        {
            if (!L.empty())
            {
                L.pop();
            }
            else
            {
                R.push(make_pair(s[i], i));
            }
            continue;
        }
    }
    while (!L.empty())
    {
        auto& t = L.top();
        s[t.second] = '0';
        L.pop();
    }
    while (!R.empty())
    {
        auto& t = R.top();
        s[t.second] = '0';
        R.pop();
    }
    string ans; 
    for (auto c : s)
    {
        if (c != '0') ans.push_back(c);
    }
    return ans;
}
