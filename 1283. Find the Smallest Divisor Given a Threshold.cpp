int smallestDivisor(vector<int>& nums, int threshold) {
    int max_nums = 0;
    for (auto i : nums) max_nums = max(max_nums, i);
    int start = 1;
    int end = max_nums;
    int ans = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int thres = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            thres += nums[i] / mid + (nums[i] % mid != 0);
        }
        if (thres > threshold)
        {
            start = mid + 1;
        }
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }
    return ans;
}
