// 28ms   slide window step =1;
vector<int> findAnagrams(string s, string p) {
    int len_s = s.size();
    int len_p = p.size();
    vector<int> v;
    if (len_s < len_p) return v;
    unordered_map<int, int> f_p;
    for (auto c : p)
    {
        f_p[c]++;
    }
    int begin = 0, end = 0, count = p.size();
    while (end < len_s)
    {
        if (f_p[s[end++]]-- > 0)
        {
            --count;
        }
        while (count == 0)
        {
            if (end - begin == len_p)
            {
                v.push_back(begin);
            }
            if (f_p[s[begin++]]++ >= 0)
            {
                ++count;
            }
        }
    }
    return v;
}

// violent method   582ms
vector<int> findAnagrams(string s, string p) {
    unordered_map<int,int> f_p;
    int len_p = p.size();
    for (auto c : p)
    {
        f_p[c]++;
    }
    vector<int> v;
    unordered_map<int,queue<int>> f_s;
    for (auto p : f_p)
    {
        queue<int> q;
        f_s[p.first] = q;
    }
    int index = 9999999;
    int len = 0;
    for (int i=0;i<s.size();i++)
    {
        char temp_c = s[i];
        if (f_p.count(temp_c))
        {
            auto& q = f_s[temp_c];
            // add a condition
            q.push(i);
            index = min(index, i);
            len++;
            // sentence the condition
            if (q.size() > f_p[temp_c])
            {
                int dumb = q.front();
                q.pop();
                --len;
                index = 9999999;
                index = min(index, q.front());
                for (auto& p_others : f_s)
                {
                    while (!p_others.second.empty() && p_others.second.front() < dumb)
                    {
                        p_others.second.pop();
                        --len;
                    }
                    if (!p_others.second.empty()) index = min(index, p_others.second.front());
                }
            }
            if (q.size() == f_p[temp_c] && len == len_p)
            {
                // answer here
                v.push_back(index);
            }  
        }
        else
        {
            f_s.clear();
            for (auto p : f_p)
            {
                queue<int> q;
                f_s[p.first] = q;
            }
            index = 9999999;
            len = 0;
        }
    }
    return v;
}
