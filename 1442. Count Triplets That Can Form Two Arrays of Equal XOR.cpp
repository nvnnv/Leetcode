int countTriplets(vector<int>& arr) {
    int len = arr.size();
    int x = 0;
    for (int i = 0; i < arr.size()-1; ++i)
    {
        int t = arr[i];
        for (int k = i + 1; k < arr.size(); ++k)
        {
            t ^= arr[k];
            if (t == 0)
            {
                x += (k - i);
            }
        }
    }
    return x;
}
