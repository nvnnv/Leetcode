/*
quite complex
1st: sort from less to greater
2nd: divide into 2 groups,assume array is 1,2,3,4,5,6,7,8,9,(10)
if size odd:
first group is 1,2,3,4,5
second group is 6,7,8,9
assume answer array is 1,x1,2,x2,3,x3,4,x4,5
according to the rule descibed by the question: when 1,2,3,4,5 are taken out, left array is x2,x3,x4,x1. So, we have to assume x2 < x4. When x2,x4 are out, left x3,x1. So, x3<x1
Hence, x2<x4<x3<x1, x2 = 6, x4 = 7, x3 = 8, x4 = 9;
solved.
if size even:
first group is 1,2,3,4,5
second group is 6,7,8,9,10
assume answer array is 1,x1,2,x2,3,x3,4,x4,5,x5
according to the rule descibed by the question: when 1,2,3,4,5 are taken out, left array is x1,x2,x3,x4,x5. So, we have to assume x1<x3<x5. When x1,x3,x5 are out, left x2,x4. So, x2<x4
Hence, x1<x3<x5<x2<x4, x1 = 6, x3 = 7, x5 = 8, x2 = 9, x4 = 10; 
solved.
*/
void xxooo(list<int>& v, list<int>& realV)
{   
    if (v.size() == 1)
    {
        realV.push_back(v.back());
        v.pop_back();
        return;
    }
    auto it = v.begin();
    if (v.size() % 2)
    {
        // odd
        while (true)
        {
            realV.push_back(*it);
            it = v.erase(it);
            if (it != v.end()) break;
            ++it;
        }
        auto front = v.front();
        v.pop_front();
        v.push_back(front);
        xxooo(v, realV);
    }
    else
    {
        // even
        while (it != v.end())
        {
            realV.push_back(*it);
            it = v.erase(it);
            ++it;
        }
        xxooo(v, realV);
    }
}
vector<int> deckRevealedIncreasing(vector<int>& deck) {
        if (deck.size() == 1) return deck;
    sort(deck.begin(), deck.end());
    list<int> q;
    int limit_L = deck.size() / 2 + deck.size() % 2;
    for (int i = 0; i < limit_L; ++i)
    {
        q.push_back(deck[i]);
    }
    int limit_R = deck.size() / 2;
    list<int> v;
    if (deck.size() % 2)
    {
        for (int i = 2; i <= limit_R; ++i) v.push_back(i);
        v.push_back(1);
    }
    else
    {
        for (int i = 1; i <= limit_R; ++i) v.push_back(i);
    }
    list<int> realV;
    xxooo(v, realV);
    auto it = q.begin();
    int i = 0;
    map<int, int> qq;
    while (!realV.empty())
    {
        int t = realV.front();
        realV.pop_front();
        qq[t] = deck[limit_L + i];
        ++i;
    }
    vector<int> x;
    i = 1;
    while (!q.empty())
    {
        x.push_back(q.front());
        q.pop_front();
        if (i <= qq.size())
        {
            x.push_back(qq[i]);
            ++i;
        }
    }
    return x;
}
