vector<int> arrayRankTransform(vector<int>& arr) {
    map<int, int> order;
    for (int i =0;i<arr.size();++i)
    {
        order[arr[i]] = i+1;
    }
    int i = 1;
    for (auto& p : order)
    {
        p.second = i++;
    }
    vector<int> x = {};
    for (auto i : arr)
    {
        x.push_back(order[i]);
    }
    return x;
}
