void combination(vector<int>& v, int i, int n, int s, int& q, vector<vector<int>>& vm)
{
    if (s > q && v.size() > n) return;
    if (s == q && v.size() == n)
    {
        vm.push_back(v);
        return;
    }
    for (int j = i; j <= 9; ++j)
    {
        v.push_back(j);
        combination(v, j+1, n, s+j, q, vm);
        v.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> v;
    vector<vector<int>> vm;
    combination(v, 1, k, 0, n, vm);
    return vm;
}
