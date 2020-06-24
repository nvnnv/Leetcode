bool canConstruct(string ransomNote, string magazine) {
    if (magazine == "" && ransomNote == "") return true;
    int len_m = magazine.size();
    unordered_map<char, int> f;
    for (auto c : magazine)
    {
        f[c]++;
    }
    unordered_map<char, int> ff;
    for (auto c : ransomNote)
    {
        ff[c]++;
    }
    for (auto p : ff)
    {
        if (!f.count(p.first))
        {
            return false;
        }
        if (f[p.first] < p.second)
        {
            return false;
        }
    }
    return true;
}
