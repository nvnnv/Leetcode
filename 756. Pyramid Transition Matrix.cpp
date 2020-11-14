int stop = 0;
void testB(string b, string n_b, int i, vector<vector<vector<int>>>& p)
{
    if (n_b.size() == b.size()-1)
    {
        b = n_b; n_b = ""; i = 1;
    }
    if (b.size() == 1)
    {
        stop = 1; return;
    }
    if (i < 1 || i >= b.size()) return;
    int x = b[i-1] - 65;
    int y = b[i] - 65;
    auto& v = p[x][y];
    for (int j = 0; j < v.size(); ++j)
    {
        auto c = v[j];
        if (!n_b.empty())
        {
            auto p_c = n_b.back();
            if (p[p_c - 65][c - 65].empty()) continue;
        }
        n_b.push_back(c);
        testB(b, n_b, i+1, p);
        if (stop == 1) return;
        n_b.pop_back();
    }
}
bool pyramidTransition(string bottom, vector<string>& allowed) {
    vector<vector<vector<int>>> f(26, vector<vector<int>>(26, vector<int>()));
    for (auto& v : allowed)
    {
        f[v[0] - 65][v[1] - 65].push_back(v[2]);
    }
    string nb = "";
    testB(bottom, nb, 1, f);
    return stop;
}
