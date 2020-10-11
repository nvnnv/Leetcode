vector<int> nextLargerNodes(ListNode* head) {
    stack<pair<int,int>> s;
    vector<int> v;
    auto n = head;
    int i = 0;
    while (n)
    {
        while (!s.empty() && s.top().second < n->val)
        {
            v[s.top().first] = n->val;
            s.pop();
        }
        s.push({ i, n->val });
        n = n->next;
        ++i;
        v.push_back(0);
    }

    return v;
}
