bool cmp6(pair<string, int>& s1, pair<string, int>& s2)
{
    if (s1.first.size() == s2.first.size()) return s1.second < s2.second;
    return s1.first.size() < s2.first.size();
}
void split_str(string& s, string& split, vector<pair<string, int>>& vs)
{
    int i = 0;
    int pos = s.find(split, i);
    while (pos != string::npos)
    {
        string x = s.substr(i, pos - i);
        vs.push_back({x, vs.size()});
        i = pos + 1;
        pos = s.find(split, i);
    }
    string x = s.substr(i);
    vs.push_back({ x, vs.size() });
}

string arrangeWords(string text) {
    if (text.empty()) return "";
    text[0] = text[0] + 32;
    vector<pair<string, int>> sv;
    string sp = " ";
    split_str(text, sp, sv);
    sort(sv.begin(), sv.end(), cmp6);
    string x = "";
    for (auto& s : sv)
    {
        x += s.first + " ";
    }
    x.pop_back();
    x[0] = x[0] - 32;
    return x;
}
