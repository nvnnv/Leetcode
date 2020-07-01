//  s[i,j] = s[j]-s[i]+v[i];
class NumArray {
public:
    vector<int> dp;
    vector<int> v;
    NumArray(vector<int>& nums) {
        int sum = 0;
        v = nums;
        dp = nums;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            dp[i] = sum;
        }
    }

    int sumRange(int i, int j) {
        return dp[j] - dp[i] + v[i];
    }
};
