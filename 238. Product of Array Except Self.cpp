vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> rr;
    int r = 1;
    for (auto i = nums.rbegin(); i != nums.rend(); ++i)
    {
        r *= *i;
        rr.push_back(r);
    }
    reverse(rr.begin(), rr.end());
    int l = nums[0];
    nums[0] = rr[1];
    for (int i = 1; i < nums.size()-1; ++i)
    {
        int t = l;
        l *= nums[i];
        nums[i] = t * rr[i + 1];
    }
    nums[nums.size() - 1] = l;
    rr = nums;
    return rr;
}
vector<int> productExceptSelf(vector<int>& nums) {
    int l = 1;
    vector<int> ll;
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
        l *= *it;
        ll.push_back(l);
    }
    int r = 1;
    vector<int> rr;
    for (auto it = nums.rbegin(); it != nums.rend(); ++it)
    {
        r *= *it;
        rr.push_back(r);
    }
    reverse(rr.begin(), rr.end());
    vector<int> s(nums.size(), 0);
    s[0] = rr[1];
    s[nums.size() - 1] = ll[nums.size() - 2];
    for (int i = 1; i < nums.size()-1; ++i)
    {
        s[i] = ll[i - 1] * rr[i + 1];
    }
    return s;
}
