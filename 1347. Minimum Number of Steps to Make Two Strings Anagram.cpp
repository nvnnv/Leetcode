// 80ms  
  static int nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:

int minSteps(string s, string t) {
    int sL = s.size();
    int tL = t.size();

    if (sL != tL) return -1;
    int sF[27];
    int sT[27];
    memset(sF, 0, 27 * sizeof(int));
    memset(sT, 0, 27 * sizeof(int));
    for (int i = 0; i < sL; ++i)
    {
        ++sF[s[i] - 96];
        ++sT[t[i] - 96];
    }
    int ans = 0;
    for (int i = 1; i <= 26; ++i)
    {
        if (sF[i] > sT[i]) ans += sF[i] - sT[i];
    }

    return ans;
}
};
 //160ms
 static int nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:

int minSteps(string s, string t) {
    int sL = s.size();
    int tL = t.size();

    if (sL != tL) return -1;
    unordered_map<char, int> sF;
    for (auto c : s)
    {
        ++sF[c];
    }
    unordered_map<char, int> sT;
    for (auto c : t)
    {
        ++sT[c];
    }
    int ans = 0;
    for (auto p : sF)
    {
        if(p.second > sT[p.first]) ans += p.second - sT[p.first];
    }
    return ans;
}
};
