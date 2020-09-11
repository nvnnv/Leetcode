int maxChunksToSorted(vector<int>& arr) {
    int must = 0;
    int ma = arr[0];
    int sum = 0;
    int n = 0;
    int chunks = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        sum += arr[i];
        ++n;
        ma = max(arr[i], ma);
        if (sum == (must*n + (n - 1) * n / 2))
        {
            ++chunks;
            must = ma + 1;
            sum=0;
            n=0;
        }
    }
    return chunks;
}
