class Solution {
public:
    int dp[1001][1001];
    int dfs(int i, int a, int b, vector<int>& nums, vector<int>& m) {
        if (i >= m.size()) return 0;
        if (dp[i][a] != 0) return dp[i][a];
        
        int f = max(dfs(i+1, a, b-1, nums, m)+ (m[i]*nums[b]), dfs(i+1, a+1, b, nums, m) + (m[i]*nums[a]));
    
        dp[i][a]= f;
        return f;
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        memset(dp, 0, sizeof(dp));
        return dfs(0, 0, nums.size()-1, nums, multipliers);
    }
};
