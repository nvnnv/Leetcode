int maxDepth(Node* root) {
    if (root == nullptr)
    {
        return 0;
    }
    vector<tuple<Node*, int,int,int>> s;
    s.push_back(make_tuple(root, 0,-1, 1));
    int depth=0;
    while (!s.empty())
    {
        auto& cur = s.back();
        if (get<1>(cur) == get<0>(cur)->children.size())
        {
            if(get<2>(cur)!= -1 ) get<1>(s[get<2>(cur)])++;
            depth = max(get<3>(cur), depth);
            s.pop_back();
            continue;
        }
        int pos = s.size()-1;
        int level = get<3>(cur);
        auto& v = get<0>(cur)->children;
        for (auto i = 0; i < v.size(); ++i)
        {
            s.push_back(make_tuple(v[i], 0, pos, level+1));
        }
    }
    return depth;
}
