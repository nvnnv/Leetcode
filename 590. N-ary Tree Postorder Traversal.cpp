vector<int> postorder(Node* root) {
    vector<tuple<Node*, int, int>> s;
    s.push_back(make_tuple(root, 0, -1));
    vector<int> v;
    if(root == NULL) return v;
    // loop show backtrack;
    while (!s.empty())
    {
        auto& cur = s.back();
        if (get<0>(cur)->children.size() == 0 || get<1>(cur) == get<0>(cur)->children.size())
        {
            v.push_back(get<0>(cur)->val);
            if(get<2>(cur) >= 0) get<1>(s[get<2>(cur)])++;
            s.pop_back();
            continue;
        }
        auto node = get<0>(cur);
        int j = s.size()-1;
        for (auto i = node->children.rbegin(); i != node->children.rend(); ++i)
        {
            s.push_back(make_tuple(*i, 0, j));
        }
    }
    return v;
}
