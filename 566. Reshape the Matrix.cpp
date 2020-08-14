vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    if (nums.size() == 0) return nums;
    int m = nums.size();
    int n = nums[0].size();
    if (m * n != r * c) return nums;
    vector<int> beFlat;
    for (auto& v : nums)
    {
        beFlat.insert(beFlat.end(), v.begin(), v.end());
    }
    int j = 0;
    vector<vector<int>> x;
    for (int i = 0; i < r; i++)
    {
        vector<int> row;
        for (int k = j; k < j+c; ++k)
        {
            row.push_back(beFlat[k]);
        }
        x.push_back(row);
        j += c;
    }
    return x;
}
