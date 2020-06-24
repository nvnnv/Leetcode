int findTheLongestSubstring(string s) {
    unordered_map<int, int> f;
    int ans = 0;
    int condition = 0;
    string vowels = "uoiea";
    f[0] = -1;
    for (int i = 0; i < s.size(); ++i)
    {
        int j = vowels.find(s[i]);
        if(j != string::npos) condition ^= 1 << j;
        if(!f.count(condition)) f.insert(make_pair(condition, i));
        ans = max(ans, i - f[condition]);
    }
    return ans;
}
