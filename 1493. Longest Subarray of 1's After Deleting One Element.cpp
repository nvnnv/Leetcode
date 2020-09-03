int longestSubarray(vector<int>& nums) {
    int p = 0;
    int x = 0;
    int m = 0;
    int b = 0;
    int c = 0;
    for (int i = 0; i < nums.size();)
    {
        while (i < nums.size() && nums[i] == 1)
        {
            ++x;
            ++i;
        }
        m = max(x, m);
        int f = 0;
        while (i < nums.size() && nums[i] == 0)
        {
            ++f;
            ++i;
            ++c;
        }
        if (f == 1)
        {
            if (b)
            {
                x -= p;
                p = x;
            }
            if (!b)
            {
                p = x;
                b = 1;
            }
        }
        else
        {
            b = 0;
            x = 0;
        }
    }
    if(c==0) --m;
    if(m < 0) m =0;
    return m;
}
