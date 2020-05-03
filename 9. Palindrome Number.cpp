// 12ms
bool isPalindrome(int x) {
    if (x < 0)
    {
        return false;
    }
    int forward = x;
    long backward = 0;
    while (x)
    {
        backward = backward * 10 + x % 10;
        x /= 10;
    }
    return forward == backward;
}
//40ms
bool isPalindrome(int x) {
    if (x < 0)
    {
        return false;
    }
    vector<int> v;
    while (x)
    {
        v.push_back(x % 10);
        x /= 10;
    }
    int l, r;
    for (l = 0, r = v.size() - 1; l <= r; ++l, --r)
    {
        if (v[l] != v[r]) return false;
    }
    return true;
}
