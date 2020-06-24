string customSortString(string S, string T) {
    if (S.size() == 0) return T;

    unordered_map<char, vector<int>> flag;
    for (auto c : S)
    {
        vector<int> a;
        flag[c] = a;
    }
    for (int i = 0; i < T.size(); ++i)
    {
        if (flag.count(T[i])) flag[T[i]].push_back(i);
    }
    string ans;
    for (auto c :S)
    {
        auto& p = flag[c];
        while (!p.empty())
        {
            ans.push_back(c);
            T[p.back()] = '0';
            p.pop_back();
        }
    }
    for (auto c : T)
    {
        if (c != '0') ans.push_back(c);
    }
    return ans;
}
