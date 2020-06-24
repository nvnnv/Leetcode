// 420ms
bool startWith(string& aim, string& match)
{
    int i = 0;
    while (i < match.size() && i <= aim.size())
    {
        if (match[i] == aim[i]) ++i;
        else break;
    }
    return i == match.size();
}
vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    vector<vector<string>> ans;
    sort(products.begin(), products.end());
    string key = "";
    for (auto c : searchWord)
    {
        key.push_back(c);
        vector<string> subAns;
        for (auto& s : products)
        {
            if (startWith(s, key))
            {
                subAns.push_back(s);
                if (subAns.size() == 3) break;
            }
        }
        ans.push_back(subAns);
    }
    return ans;
}



// 120ms
bool startWith(string& aim, string& match)
{
    int i = 0;
    while (i < match.size() && i <= aim.size())
    {
        if (match[i] == aim[i]) ++i;
        else break;
    }
    return i == match.size();
}
vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    vector<vector<string>> ans;
    sort(products.begin(), products.end());
    string key = "";
    for (auto c : searchWord)
    {
        key.push_back(c);
        vector<string> subAns;
        for (auto& s : products)
        {
            if (startWith(s, key))
            {
                subAns.push_back(s);
            }
        }
        products = subAns;
        while (subAns.size() > 3)
        {
            subAns.pop_back();
        }
        ans.push_back(subAns);
    }
    return ans;
}
