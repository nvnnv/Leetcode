vector<int> selfDividingNumbers(int left, int right) {
    vector<int> ans;
    for (int i = left; i <= right; ++i)
    {
        int temp = i;
        int f = true;
        while (temp)
        {
            int t1 = temp % 10;
            temp /= 10;
            if (t1 ==0 || i % t1 != 0)
            {
                f = false;
            }
        }
        if (f) ans.push_back(i);
    }
    return ans;
}
