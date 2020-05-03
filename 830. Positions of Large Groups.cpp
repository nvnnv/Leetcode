vector<vector<int>> largeGroupPositions(string S) {
    int left = 0;
    int right = 0;
    vector<vector<int>> ans;
    for (int i = 1; i < S.size(); ++i)
    {
        if (S[i] == S[i - 1])
        {
            left = i - 1;
            while (++i < S.size() && S[i] == S[i - 1]);
            right = i - 1;
            if (right - left + 1 >= 3)
            {
                vector<int> t = { left, right };
                ans.push_back(t);
            }
        }
    }
    return ans;
}
