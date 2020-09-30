vector<int> maxDepthAfterSplit(string seq) {
    if (seq.size() < 2) return {};
    int a_c = 0;
    int b_c = 0;

    vector<int> group(seq.size(), 0);
    for (int i = 0; i < seq.size(); ++i)
    {
        if (seq[i] == '(')
        {
            if (a_c <= b_c)
            {
                group[i] = 0;
                ++a_c;
            }
            else
            {
                group[i] = 1;
                ++b_c;
            }
        }
        if (seq[i] == ')')
        {
            if (a_c >= b_c)
            {
                group[i] = 0;
                --a_c;
            }
            else
            {
                group[i] = 1;
                --b_c;
            }
        }

    }

    return group;
}
