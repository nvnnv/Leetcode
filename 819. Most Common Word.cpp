string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_map<string, int> flag;
    for (auto& c : paragraph)
    {
        c = tolower(c);
    }
    paragraph += " ";
    int j = 0;
    for (int i = 0; i < paragraph.size(); ++i)
    {
        if (paragraph[i] >= 97 && paragraph[i] <= 122) continue;
        else
        {
            flag[paragraph.substr(j, i-j)]++;
            while (i < paragraph.size() && paragraph[i] < 97 || paragraph[i] > 122) ++i;
            j = i;
            --i;
        }
    }
    int maximum = 0;
    string& ans = paragraph;
    for (auto s : banned)
    {
        if (flag.count(s) > 0) flag[s] = -1;
    }
    for (auto p : flag)
    {
        if (maximum < p.second)
        {
            ans = p.first;
            maximum = p.second;
        }
    }
    return ans;
}
