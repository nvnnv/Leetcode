int arrayNesting(vector<int>& nums) {
    unordered_set<int> s;
    int len = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (s.count(nums[i]) == 0)
        {
            int j = nums[i];
            s.insert(j);
            int l = 1;
            while (j != i)
            {
                j = nums[j];
                s.insert(j);
                ++l;
            }
            len = max(len, l);
        }
    }
    return len;
}
