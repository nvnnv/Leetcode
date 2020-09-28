struct cmp3
{
    bool operator()(const pair<int,int>& p1, const pair<int,int>& p2)
    {
        if (p1.second == p2.second) return p1.first > p2.first;
        return p1.second < p2.second;
    }
};

int leastInterval(vector<char>& tasks, int n) {
    // pre-processed
    vector<int> a(26, 0);
    for (auto i : tasks)
    {
        a[i - 65]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp3> b;
    for (int i = 0; i < 26; ++i)
    {
        if (a[i]) b.push(make_pair(i, a[i]));
    }
    // end
    int consumption = 0;
    while (!b.empty())
    {
        vector<pair<int, int>> x;
        if (b.size() > n)
        {
            for (int i = 0; i <= n; ++i)
            {
                auto p = b.top();
                b.pop();
                p.second--;
                x.push_back(p);
            }
            for (auto& p : x)
            {
                if(p.second)b.push(p);
            }
            consumption += n + 1;
        }
        else
        {

            while (!b.empty())
            {
                ++consumption;
                auto p = b.top();
                b.pop();
                p.second--;
                x.push_back(p);
            }
            for (auto& p : x)
            {
                if (p.second)b.push(p);
            }
            if (!b.empty()) consumption += (n-x.size()+1);
        }
    }
    return consumption;
}
