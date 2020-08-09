stringstream ss;
void jigsaw(TreeNode* cur, vector<vector<string>>& graph)
{
    if (cur->left == nullptr && cur->right == nullptr)
    {
        ss.clear();
        string s;
        ss << cur->val;
        ss >> s;
        vector<string> vs = { s };
        graph.push_back(vs);
        return;
    }
    vector<vector<string>> g1;
    if (cur->left)
    {
        jigsaw(cur->left, g1);
    }
    vector<vector<string>> g2;
    if (cur->right)
    {
        jigsaw(cur->right, g2);
    }
    // merge
    vector<vector<string>> g;
    if (g1.size() < g2.size())
    {
        for (int i = 0; i < g2.size(); ++i)
        {
            if (i < g1.size())
            {
                if (g1[i].size() < g2[i].size())
                {
                    int g1_break = g1[i].size() / 2;
                    int g2_break = g2[i].size() / 2;
                    if (g1_break == 0)
                    {
                        int blank = (g2[i].size() - g1[i].size()) / 2;
                        vector<string>_t;
                        for (int j = 0; j < blank; ++j) _t.push_back("");
                        g1[i].insert(g1[i].begin(), _t.begin(), _t.end());
                        g1[i].insert(g1[i].end(), _t.begin(), _t.end());
                    }
                    else
                    {
                        vector<string> t1;
                        for (int j = 0; j < g1_break; ++j)
                        {
                            t1.push_back(g1[i][j]);
                        }
                        int blank = (g2_break - g1_break) / 2;
                        vector<string>_t;
                        for (int j = 0; j < blank; ++j) _t.push_back("");
                        t1.insert(t1.begin(), _t.begin(), _t.end());
                        t1.insert(t1.end(), _t.begin(), _t.end());
                        vector<string> t0 = { g1[i][g1_break] };
                        vector<string> t2;
                        for (int j = g1_break + 1; j < g1[i].size(); ++j)
                        {
                            t2.push_back(g1[i][j]);
                        }
                        t2.insert(t2.begin(), _t.begin(), _t.end());
                        t2.insert(t2.end(), _t.begin(), _t.end());
                        vector<string> t;
                        t.insert(t.end(), t1.begin(), t1.end());
                        t.insert(t.end(), t0[0]);
                        t.insert(t.end(), t2.begin(), t2.end());
                        g1[i] = t;
                    }
                }
                vector<string> m;
                m.insert(m.end(), g1[i].begin(), g1[i].end());
                m.push_back("");
                m.insert(m.end(), g2[i].begin(), g2[i].end());
                g.push_back(m);
            }
            else
            {
                vector<string> t;
                for (int j = 0; j < g2[i].size(); ++j) t.push_back("");
                vector<string> m;
                m.insert(m.end(), t.begin(), t.end());
                m.push_back("");
                m.insert(m.end(), g2[i].begin(), g2[i].end());
                g.push_back(m);
            }

        }
    }
    if (g2.size() < g1.size())
    {
        for (int i = 0; i < g1.size(); ++i)
        {
            if (i < g2.size())
            {
                if (g1[i].size() > g2[i].size())
                {
                    int g1_break = g1[i].size() / 2;
                    int g2_break = g2[i].size() / 2;
                    if (g2_break == 0)
                    {
                        int blank = (g1[i].size() - g2[i].size()) / 2;
                        vector<string>_t;
                        for (int j = 0; j < blank; ++j) _t.push_back("");
                        g2[i].insert(g2[i].begin(), _t.begin(), _t.end());
                        g2[i].insert(g2[i].end(), _t.begin(), _t.end());
                    }
                    else
                    {
                        vector<string> t1;
                        for (int j = 0; j < g2_break; ++j)
                        {
                            t1.push_back(g2[i][j]);
                        }
                        int blank = (g1_break - g2_break) / 2;
                        vector<string>_t;
                        for (int j = 0; j < blank; ++j) _t.push_back("");
                        t1.insert(t1.begin(), _t.begin(), _t.end());
                        t1.insert(t1.end(), _t.begin(), _t.end());
                        vector<string> t0 = { g2[i][g2_break] };
                        vector<string> t2;
                        for (int j = g2_break + 1; j < g2[i].size(); ++j)
                        {
                            t2.push_back(g2[i][j]);
                        }
                        t2.insert(t2.begin(), _t.begin(), _t.end());
                        t2.insert(t2.end(), _t.begin(), _t.end());
                        vector<string> t;
                        t.insert(t.end(), t1.begin(), t1.end());
                        t.insert(t.end(), t0[0]);
                        t.insert(t.end(), t2.begin(), t2.end());
                        g2[i] = t;
                    }
                }
                vector<string> m;
                m.insert(m.end(), g1[i].begin(), g1[i].end());
                m.push_back("");
                m.insert(m.end(), g2[i].begin(), g2[i].end());
                g.push_back(m);
            }
            else
            {
                vector<string> t;
                for (int j = 0; j < g1[i].size(); ++j) t.push_back("");
                vector<string> m;
                m.insert(m.end(), g1[i].begin(), g1[i].end());
                m.push_back("");
                m.insert(m.end(), t.begin(), t.end());
                g.push_back(m);
            }

        }
    }
    if (g1.size() == g2.size())
    {
        for (int i = 0; i < g1.size(); ++i)
        {
            vector<string> m;
            m.insert(m.end(), g1[i].begin(), g1[i].end());
            m.push_back("");
            m.insert(m.end(), g2[i].begin(), g2[i].end());
            g.push_back(m);
        }
    }
    vector<string> m;
    int blank = g[0].size() / 2;
    for (int i = 0; i < blank; ++i) m.push_back("");
    ss.clear();
    string s;
    ss << cur->val;
    ss >> s;
    m.push_back(s);
    for (int i = 0; i < blank; ++i) m.push_back("");
    g.insert(g.begin(), m);
    graph = g;
}
vector<vector<string>> printTree(TreeNode* root) {
    if (root == nullptr) return {};
    vector<vector<string>> graph;
    jigsaw(root, graph);
    return graph;
}
