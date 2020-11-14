unordered_map<int, vector<int>> pic;
vector<int> a;
void findquietest( vector<int>& quiet, int i, int& q, int& h)
{   
    if (a[i] != -1)
    {
        q = quiet[a[i]]; h = a[i];
        return;
    }
    int min_q = quiet[i];
    int r_h = i;
    for (int j = 0; j < pic[i].size(); ++j)
    {
        int q = min_q; int h = i;
        findquietest(quiet, pic[i][j], q, h);
        if (q < min_q)
        {
            min_q = q; r_h = h;
        }
    }
    a[i] = r_h;
    q = min_q; h = r_h;
}
vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    for (auto& v : richer)
    {
        if (!pic.count(v[1]))
        {
            vector<int> vv;
            pic[v[1]] = vv;
        }
        pic[v[1]].push_back(v[0]);
    }
    for (int i = 0; i < quiet.size(); ++i)
    {
        a.push_back(-1);
    }
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] == -1)
        {
            int q = quiet[i]; int h = i;
            findquietest(quiet, i, q, h);
        }
    }
    return a;
}
