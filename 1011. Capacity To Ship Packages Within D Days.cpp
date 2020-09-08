int shipWithinDays(vector<int>& weights, int D) {
    int s = 0;
    for (auto i : weights) s += i;
    int down = 1;
    int up = s;
    int w = 0;
    while ((up - down) > 1)
    {
        w = (down + up) / 2;
        int s = 0;
        int k = 0;
        for (int i = 0; i < weights.size(); ++i)
        {
            s += weights[i];
            if (weights[i] > w)
            {
                k = D + 1;
                break;
            }
            if (s > w)
            {
                s = weights[i];
                ++k;
            }
            if (s == w)
            {
                s = 0;
                ++k;
            }
        }
        if (s != 0) ++k;
        if (k > D)
        {
            down = w;
        }
        if (k <= D)
        {
            up = w;
        }
    }
    return up;
}
