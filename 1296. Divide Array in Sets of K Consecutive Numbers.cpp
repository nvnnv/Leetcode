
bool isPossibleDivide(vector<int>& nums, int k) {
    int len = nums.size();
    if (len % k) return false;
    unordered_map<int, int> count;
    int start = nums[0];
    for (auto i : nums)
    {
        count[i]++;
        start = min(i, start);
    }
    int leftTimes = len / k;
    while (leftTimes)
    {
        // choose k
        for (int i = 0; i < k; ++i)
        {
            if (count[start] == 0) return false;
            count[start]--;
            start++;
        }

        // update start
        start = 1e9;
        for (auto& p : count)
        {
            if (p.second) start = min(start, p.first);
        }
        --leftTimes;
    }
    return true;
}
