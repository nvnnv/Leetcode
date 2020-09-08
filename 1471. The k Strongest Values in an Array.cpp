public:
vector<int> getStrongest(vector<int>& arr, int k) {
    if(arr.size() == 1) return arr;
    sort(arr.begin(), arr.end());
    int index = (arr.size() - 1) / 2;
    int m = arr[index];
    vector<int> strong;
    int left = 0;
    int right = arr.size() - 1;
    while (k > 0)
    {
        int t1 = abs(arr[left] - m);
        int t2 = abs(arr[right] - m);
        if (t2 >= t1)
        {
            int x = right;
            while (arr[x] == arr[right] && k>0)
            {
                strong.push_back(arr[right--]);
                --k;
            }
        }
        if (t2 <= t1 && k>0)
        {
            int x = left;
            while (arr[x] == arr[left] && k > 0)
            {
                strong.push_back(arr[left++]);
                --k;
            }
        }
    }
    return strong;
}
