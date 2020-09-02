void oxoxox(int i, vector<int>& n, vector<vector<int>>& ans, vector<int>& trace, unordered_set<bitset<1000>>& x,bitset<1000>& bit)
{
    if (x.count(bit)) return;
    if (trace.size() != 0)
    {
        x.insert(bit);
        ans.push_back(trace);
    }
    for (int j = i; j < n.size(); ++j)
    {
        trace.push_back(n[j]);
        bit[j] = 1;
        oxoxox(j + 1, n, ans, trace, x, bit);
        bit[j] = 0;
        trace.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> trace;
    unordered_set<bitset<1000>> x;
    bitset<1000> bit;
    oxoxox(0, nums, ans, trace, x, bit);
    ans.push_back({});
    return ans;
}
