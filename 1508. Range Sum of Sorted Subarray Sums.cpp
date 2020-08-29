int rangeSum(vector<int>& nums, int n, int left, int right) {
    int mod = 1000000007;
    priority_queue <pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
    for (int i = 0; i < nums.size(); ++i)
    {
        q.push(make_pair(nums[i], i));
    }
    vector<int> x;
    int s = 0;
    for(int i=1; i<=right;++i)
    {
        auto t = q.top();
        q.pop();
        x.push_back(t.first);
        ++t.second;
        if (i >= left)
        {
            s += t.first;
            s = s%mod;
        }
        if (t.second < nums.size())
        {
            t.first += nums[t.second];
            t.first = t.first%mod;
            q.push(t);
        }
    }
    return s;
}
