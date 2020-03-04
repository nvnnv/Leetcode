// 2 years ago completed
class Solution {
public:
    string longestPalindrome(string s) {
    int a = 0 , b = 0 , c = 0, d = 0;
    map<int, vector<int>> xm;
    for(auto c : s)
    {
        vector<int> xv;
        xm[c] = xv;
    }
    xm[s[0]].push_back(0);
    for(int i=1;i<s.length();++i)
    {
        if(!xm[s[i]].empty())
        {
            auto vc = xm[s[i]];
            for(int j : vc)
            {
                int ax = j;
                int bx = i;
                a = ax; b = bx;
                while(ax < bx)
                {
                    if(s[ax] == s[bx])
                    {
                        ++ax;
                        --bx;
                    }
                    else
                    {
                        break;
                    }
                    if((ax == bx) || ((ax - bx) == 1))
                    {
                        if(b-a > d-c)
                        {
                            d=b;
                            c=a;
                        }
                    }
                }
            }
        }
        xm[s[i]].push_back(i);
    }
    return s.substr(c, d-c+1);
    }
};
