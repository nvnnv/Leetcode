int findSpecialInteger(vector<int>& arr) {
    if (arr.size() == 0) return 0;
    int fre = 1;
    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] == arr[i - 1])
        {
            fre++;
            if (fre > arr.size() / 4) return arr[i];
        }
        else fre = 1;
    }
    return arr[0];
}
