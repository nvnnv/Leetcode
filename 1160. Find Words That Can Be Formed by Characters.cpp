// first way 432ms
int countCharacters(vector<string>& words, string chars) {
    unordered_map<int, int> ch;
    for (auto c : chars)
    {
        ch[c]++;
    }
    int s = 0;
    for (auto& v : words)
    {
        auto i = ch;
        bool f = true;
        for (auto c : v)
        {
            if (i[c] == 0)
            {
                f = false;
            }
            if (i[c] > 0) i[c]--;
        }
        if (f) s += v.size();
    }
    return s;
}

// second way 220ms
int countCharacters(vector<string>& words, string chars) {
    unordered_map<int, int> ch;
    for (auto c : chars)
    {
        ch[c]++;
    }
    int s = 0;
    for (auto& v : words)
    {
        map<int, int> x;
        bool f = true;
        for (auto c : v)
        {
            x[c]++;
            if (x[c] > ch[c])
            {
                f = false;
                break;
            }
        }
        if (f) s += v.size();
    }
    return s;
}

// third way 143ms
int countCharacters(vector<string>& words, string chars) {
    array<int, 26> ch = {};
    for (auto c : chars)
    {
        ch[c - 'a']++;
    }
    int s = 0;
    for (auto& v : words)
    {
        array<int, 26> cv = {};
        bool f = true;
        for (auto c : v)
        {
            cv[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (cv[i] > ch[i])
            {
                f = false;
                break;
            }
        }
        if (f) s += v.size();
    }  
    return s;
}
