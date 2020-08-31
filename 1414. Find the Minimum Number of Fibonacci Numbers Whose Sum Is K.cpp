int findMinFibonacciNumbers(int k) {
    vector<int> Fib = {1,1};
    for (int i = 2; i < 44; ++i)
    {
        Fib.push_back(Fib[i - 1] + Fib[i - 2]);
    }
    int c = 0;
    for (auto it = Fib.rbegin(); it != Fib.rend(); ++it)
    {
        if (*it <= k)
        {
            int t = k;
            while (t > 0)
            {
                t -= *it;
                ++c;
            }
            if (t == 0) break;
            k = t + *it;
            --c;
        }
    }
    return c;
}
