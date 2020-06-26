int subarraysDivByK(vector<int>& A, int K) {
    unordered_map<int, int> f;
    int sum = 0;
    int ans = 0;
    f[0] = 1;
    for (int i = 0; i < A.size(); ++i)
    {
        sum += A[i];
        int mod = sum % K;
        if (f.count(mod))
        {
            ans += f[mod];
        }
        if (f.count(mod - K))
        {
            ans += f[mod-K];
        }
        if (f.count(mod + K))
        {
            ans += f[mod + K];
        }
        f[mod]++;
    }
    return ans;
}
