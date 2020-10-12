string removeDuplicates(string s, int k) {
    vector<pair<int,int>> st;
    for (int i = 0; i < s.size(); ++i)
    {
        if (!st.empty())
        {
            if (st.back().first == s[i]) st.push_back({ s[i], st.back().second + 1 });
            else st.push_back({ s[i],1 });
        }
        else
        {
            st.push_back({ s[i], 1 });
        }
        if (st.back().second == k)
        {
            int j = k;
            while (j--) st.pop_back();
        }
    }
    string ans;
    for (auto i : st)  ans.push_back(i.first);
    return ans;
}
