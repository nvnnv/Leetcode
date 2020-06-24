bool queryString(string S, int N) {
    
    for (int i = N; i > N / 2; --i)
    {
        bitset<32> a(i);
        auto s = a.to_string();
        if (S.find(s.substr(s.find('1'))) == string::npos)
        {
            return false;
        }
    }
    return true;
}
// above the second way


void subStr(list<char>& s, string& ss, int be, int si)
{
    if (s.size() == 0)
    {
        for (int i = be; i < si; ++i)
        {
            s.push_back(ss[i]);
        }
    }
    else
    {
        s.pop_front();
        s.push_back(ss[be + si - 1]);
    }
}
int binaryToInt(list<char>& s)
{
    int sum = s.back()-48;
    int j = 0;
    int power = 1;
    auto i = s.rbegin();
    ++i;
    for (i; i != s.rend(); ++i)
    {
        power *= 2;
        if (*i == '1')
        {
            sum += power;
        }
    }
    return sum;
}
bool queryString(string S, int N) {
    int i = 2;
    int j = 1;
    while (i < N)
    {
        i = i * 2;
        ++j;
    }
    list<char> subS;
    int len_s = S.size();
    set<int> ans;
    for (int i = 1; i <=j; ++i)
    {
        int k = 0;
        subS.clear();
        while (k <= len_s - i)
        {
            subStr(subS, S, k, i);
            ans.insert(binaryToInt(subS));
            ++k;
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        if (ans.count(i) == 0) return false;
    }
    return true;
}
