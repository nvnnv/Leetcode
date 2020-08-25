int minStartValue(vector<int>& nums) {
    int x = 1;
    int y = x;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (y + nums[i] < 1)
        {
            x += abs(y + nums[i]) + 1;
            y += abs(y + nums[i]) + 1;
        }
        y += nums[i];
    }
    return x;
}
