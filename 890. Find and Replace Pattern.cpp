class Solution {
public:
vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> ans;
    int len_pa = pattern.size();
    int j = 0;
    vector<int> p2;
    unordered_map<char, char> true_pa1;
    unordered_map<char, char> true_pa2;
    for (int i = 1;i<len_pa; ++i)
    {
        if (pattern[i] != pattern[i - 1])
        {
            p2.push_back(-1);
            p2[j] = i - j;
            j = i;
        }
        else
        {
            p2.push_back(-1);
        }
    }
    p2.push_back(-1);
    p2[j] = len_pa - j;
    for (auto& s : words)
    {
        int len_s = s.size();
        if (len_pa != len_s) continue;
        int f = 1;
        for (int i = 0; i < len_s;)
        {
            if (true_pa2[pattern[i]] == 0 && true_pa1[s[i]] == 0)
            {
                true_pa2[pattern[i]] = s[i];
                true_pa1[s[i]] = pattern[i];
            }
            if (true_pa2[pattern[i]] != s[i])
            {
                f = 0;
                break;
            }
            int k = p2[i];
            int x = 1;
            while (x <= k - 1 && s[i] == s[i + x]) ++x;
            if (x != k)
            {
                f = 0;
                break;
            }
            i = i+k;
        }
        if (f) ans.push_back(s);
        true_pa2.clear();
        true_pa1.clear();
    }
    return ans;
}
};
