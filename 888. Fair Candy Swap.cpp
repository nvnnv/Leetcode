vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int sum_A = 0;
    int sum_B = 0;
    unordered_set<int> _A;
    unordered_set<int> _B;
    for (auto i : A)
    {
        sum_A += i;
        _A.insert(i);
    }
    for (auto i : B)
    {
        sum_B += i;
        _B.insert(i);
    }
    int minus = abs(sum_A - sum_B)/2;
    int equals = min(sum_A, sum_B) + minus;
    int re_A = 0;
    int re_B = 0;
    for (auto i : A)
    {
        int t = sum_A - i;
        if (_B.count(equals - t))
        {
            re_B = equals - t;
            re_A = i;
            break;
        }
    }
    return { re_A, re_B };
}
