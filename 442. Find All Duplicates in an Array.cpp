vector<int> findDuplicates(vector<int>& nums) {
    if (nums.size() < 2) return {};
    vector<int> x;
    for (int i = 0; i < nums.size(); i++)
    {
        int val = nums[i];
        if (val < 0)
        {
            if (nums[abs(val) - 1] < 0)
            {
                x.push_back(abs(val));
            }
            else
            {
                nums[abs(val) - 1] = -nums[abs(val) - 1];
            }
        }
        if (val > 0)
        {
            if (nums[val - 1] < 0)
            {
                x.push_back(val);
            }
            else
            {
                nums[val - 1] = -nums[val - 1];
            }
        }
    }
    return x;
}
