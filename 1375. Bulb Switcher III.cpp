int numTimesAllBlue(vector<int>& light) {
    long long s = 0;
    int c = 0;
    for (int i = 0; i < light.size(); ++i)
    {
        s += light[i];
        long long m = 0;
        if (((i + 1) % 2) == 0)
        {
            m = (i + 1) / 2 * i + i + 1;
        }
        else
        {
            m = i / 2 * (i + 1) + i + 1;
        }
        if (s == m)
        {
            ++c;
        }
    }
    return c;
}
