void doA(string& s, int a, int b, string& re)
{
    string t = s;
    int o_2 = 9;
    while (true)
    {
        for (int i = 1; i < t.size(); i += 2)
        {
            t[i] = (t[i] - 48 + a) % 10 + 48;
        }
        if (t[1] - 48 < o_2)
        {
            re = t;
            o_2 = t[1] - 48;
        }
        if (t == s) break;
    }
}
void xxxooo1(string s, int a, int b, string& ans, unordered_set<string>& sset)
{
    if (sset.count(s)) return;
    sset.insert(s);
    string t = s;
    while (true)
    {
        string re = t;
        for (int i = 1; i < re.size(); i += 2)
        {
            re[i] = (re[i] - 48 + a) % 10 + 48;
        }
        xxxooo1(re, a, b, ans, sset);
        if (ans > re) ans = re;
        string q = t.substr(t.size() - b);
        string p = t.substr(0, t.size() - b);
        t = q + p;
        if (t == s) break;
        if (sset.count(t)) break;
    }
}
string findLexSmallestString(string s, int a, int b) {
    string ans = s;
    if (b % 2 == 1)
    {
        unordered_set<string> sset;
        xxxooo1(s, a, b, ans, sset);
    }
    else
    {
        string t = s;
        while (true)
        {
            string re = t;
            doA(t, a, b, re);
            if (ans > re) ans = re;
            string q = t.substr(t.size() - b);
            string p = t.substr(0, t.size() - b);
            t = q + p;
            if (t == s) break;
        }
    }
    return ans;
}




class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int):

        def add_a(_s: list, a, x):
            m = _s[x]
            k = _s[x]
            r = _s
            while True:
                for i in range(x, len(_s), 2):
                    _s[i] += a
                    _s[i] %= 10
                if _s[x] < k:
                    k = _s[x]
                    r = copy.deepcopy(_s)
                if _s[x] == m:
                    break
            return r


        x = s
        t = s
        if b % 2 == 0:
            for _ in range(len(s)//gcd(len(s), b)):
                p = [int(i) for i in t]
                q = add_a(p, a, 1)
                t = t[len(t)-b:] + t[0:len(t) - b]
                if x > "".join(map(str, q)):
                    x = "".join(map(str, q))
        else:
            for _ in range(len(s)//gcd(len(s), b)):
                p = [int(i) for i in t]
                q = add_a(p, a, 1)
                q = add_a(q, a, 0)
                t = t[len(t)-b:] + t[0:len(t) - b]
                if x > "".join(map(str, q)):
                    x = "".join(map(str, q))

        return x
