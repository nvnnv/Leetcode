
string reverseParentheses(string s) {
    stack<int> pos;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            pos.push(i);
        }
        if (s[i] == ')')
        {
            if (!pos.empty())
            {
                auto j = pos.top();
                pos.pop();
                reverse(s.begin() + j + 1, s.end() - (s.size() - i));
            }
        }
    }
    string x;
    for (auto c : s)
    {
        if (c != '(' && c != ')') x.push_back(c);
    }
    return x;
}
