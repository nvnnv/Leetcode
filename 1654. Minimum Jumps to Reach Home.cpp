class Solution {
public:
    int dp[6000][2];
    unordered_map<int, int> forbi;
    int dfs(int i, bool back, int forward, int goback, int goal) {
        if (i==goal) return 0;
        if (i<0 || i >= 6000 || forbi.count(i) == 1) return 1e9;
        if (dp[i][back] != -1) return dp[i][back];
        
        dp[i][back] = dfs(i+forward, false, forward, goback, goal)+1;
        if (!back) dp[i][back] = min(dp[i][back], dfs(i-goback, true, forward, goback, goal)+1);
        return dp[i][back];
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        for (int i : forbidden) forbi[i] =1;
        memset(dp, -1, sizeof(dp));
        int p = dfs(0, false, a, b, x);
        if (p >= 1e9) return -1;
        else return p;
    }
};
