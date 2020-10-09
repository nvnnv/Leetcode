
int minEatingSpeed(vector<int>& piles, int H) {
    if (piles.size() <= 0) return 0;
    sort(piles.begin(), piles.end());
    int mi = 1;
    int ma = 1e9;
    int ans = 0;
    while (mi <= ma)
    {
        int m = (mi + ma) / 2;
        // can 'm' eat all ?
        int h = 0;
        for (auto i : piles)
        {
            h += i / m + (i % m > 0);
        }
        if (h > H) mi = m + 1;
        else
        {
            ma = m - 1;
            ans = m;
        }
    }
    return ans;
}
