bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> sum_times;
    int sum = 0;
    int temp = 0;
    k = abs(k);
    sum_times[0] = -1;
    for (int i =0;i<nums.size();++i)
    {
        sum += nums[i];
        if (k == 0)
        {
            if (sum_times.count(sum))
            {
                if (i - sum_times[sum] >= 2) return 1;
            }
        }
        else
        {
                int remainder = sum % k;
                int n = sum / k;
                // n=0 n=n   remainder = 0
                for (int j = 0; j <= n; ++j)
                {
                    temp = remainder + j * k;
                    if (sum_times.count(temp))
                    {
                        if (i - sum_times[temp] >= 2) return 1;
                    }
                }
        }
        if(!sum_times.count(sum))sum_times.insert(make_pair(sum, i));
    }
    return 0;
}
