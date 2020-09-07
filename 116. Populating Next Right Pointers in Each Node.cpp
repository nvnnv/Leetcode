void oxox(Node* cur, int level, vector<stack<Node*>>& x)
{
    if (cur == nullptr) return;
    if (x.size() == level)
    {
        stack<Node*> s;
        x.push_back(s);
    }
    auto& s = x[level];
    if (!s.empty())
    {
        s.top()->next = cur;
    }
    x[level].push(cur);
    oxox(cur->left, level + 1, x);
    oxox(cur->right, level + 1, x);
}
Node* connect(Node* root) {
    vector<stack<Node*>> x;
    oxox(root, 0, x);
    return root;
}
