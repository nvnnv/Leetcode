// unoptimized version   TLE
void getMctFromLeafV(vector<int> curLayer, int s, int& ans)
{
    int len = curLayer.size();
    int m = 0;
    for (int i = 0; i < len-1; ++i)
    {
        int x = curLayer[i] * curLayer[i+1];
        vector<int> next;
        for (int j = 0; j < i; ++j)next.push_back(curLayer[j]);
        next.push_back(max(curLayer[i], curLayer[i+1]));
        for (int k = i + 2; k < len; ++k) next.push_back(curLayer[k]);
        getMctFromLeafV(next, s+x, ans);
    }
    if(len == 1) ans = min(ans, s);
}
int mctFromLeafValues(vector<int>& arr) {
    int ans = 9999999;
    getMctFromLeafV(arr, 0, ans);
    return ans;
}

// optmized version 4ms
void getMctFromLeafV(vector<int> curLayer, int s, int& ans)
{
    int len = curLayer.size();
    if (len == 1)
    {
        ans = min(ans, s);
        return;
    }
    int pos = 0;
    int prev = 9999999;
    vector<int> next;
    for (int i = 0; i < len-1; ++i)
    {
        int x = curLayer[i] * curLayer[i+1];
        if (x < prev)
        {
            prev = x;
            pos = i;
        }
    }
    for (int j = 0; j < pos; ++j)next.push_back(curLayer[j]);
    next.push_back(max(curLayer[pos], curLayer[pos + 1]));
    for (int k = pos + 2; k < len; ++k) next.push_back(curLayer[k]);
    getMctFromLeafV(next, s + prev, ans);
    if(len == 1) ans = min(ans, s);
}
int mctFromLeafValues(vector<int>& arr) {
    int ans = 9999999;
    getMctFromLeafV(arr, 0, ans);
    return ans;
}
