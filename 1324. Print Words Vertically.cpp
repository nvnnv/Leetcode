vector<string> printVertically(string s) {
    vector<string> s_set;
    string temp = "";
    int max = 0;
    for (auto c : s)
    {
        if (c == ' ')
        {
            max = max < temp.size() ? temp.size() : max;
            s_set.push_back(temp); 
            temp = "";
        }
        else
        {
            temp.push_back(c);
        }
    }
    max = max < temp.size() ? temp.size() : max;
    s_set.push_back(temp);
    temp = "";
    vector<string> y_set;
    bool f = false;
    for (int i =0;i<max;++i)
    {
        for (auto& s : s_set)
        {
            if (i+1 > s.size())
            {
                temp.push_back(' ');
            }
            else
            {
                temp.push_back(s[i]);
                f = true;
            }
        }
        y_set.push_back(temp);
        temp = "";
    }
    for (auto& s : y_set)
    {
        for (int i=s.size()-1; i>=0;--i)
        {
            if (s[i] == ' ')
            {
                s.erase(i);
            }
            else
            {
                break;
            }
        }
    }
    return y_set;
}
