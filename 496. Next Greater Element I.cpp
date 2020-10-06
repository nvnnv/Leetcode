// 8ms
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> v;
    unordered_map<int, int> mp;
    stack<int> s;
    for (auto i = nums2.rbegin(); i != nums2.rend(); ++i)
    {
        while (!s.empty() && *i >= s.top()) s.pop();
        if (s.empty()) mp[*i] = -1;
        else mp[*i] = s.top();
        s.push(*i);
    }
    for (auto i : nums1)
    {
        v.push_back(mp[i]);
    }
    return v;
}

// 27ms
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> v;
    for (auto i : nums1)
    {
        bool f = false;
        bool x = false;
        for (auto ii : nums2)
        {
            if (ii == i) f = true;
            if (f)
            {
                if (ii > i)
                {
                    x = true;
                    v.push_back(ii);
                    break;
                }
            }
        }
        if(!x) v.push_back(-1);

    }
    return v;
}
