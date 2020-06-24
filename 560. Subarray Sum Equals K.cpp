int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> sum_times;
    int ans = 0;
    int sum = 0;
    sum_times[0] = 1;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
        ans += sum_times[sum - k];
        sum_times[sum]++;
    }
    return ans;
}
