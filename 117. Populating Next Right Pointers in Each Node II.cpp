Node* connect(Node* root) {
    if (root == nullptr) return nullptr;
    queue<Node*>  q1;

    q1.push(root);

    while (!q1.empty())
    {
        int size = q1.size();
        Node* last = nullptr;
        for (int i = 0; i < size; ++i)
        {
            auto c = q1.front();
            q1.pop();
            if (last) last->next = c;
            last = c;
            if (c->left) q1.push(c->left);
            if (c->right) q1.push(c->right);
        }
    }
    return root;
}
