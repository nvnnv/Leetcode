// 8ms
int findMax(vector<int>& A, int L, int M)
{
    int left = 0;
    int right = 0;
    int rightMax = 0;
    int x = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        left += A[i];
        if (i >= L)
        {
            left -= A[i-L];
            right += A[i - L];
        }
        if (i - L >= M)
        {
            right -= A[i - L - M];
        }
        rightMax = max(rightMax, right);
        x = max(x, rightMax + left);
    }
    return x;
}
int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
    return max(findMax(A, L, M), findMax(A, M, L));
}

// 40ms
int findNMax(vector<int>& v, int n, vector<pair<int,pair<int,int>>>& p)
{
    int i = 0;
    int j = i + n;
    int s = 0;
    for (int k = i; k < j; ++k) s += v[k]; 
    p.push_back(make_pair(s, make_pair(i, j-1)));
    int m = s;
    for (int k = j; k < v.size(); ++k)
    {
        m = m + v[k] - v[k - n];
        p.push_back(make_pair(m,  make_pair(k - n + 1, k)));
    }
    return s;
}
int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
    vector<pair<int, pair<int, int>>> x;
    vector<pair<int, pair<int, int>>> y;
    findNMax(A, L, x);
    findNMax(A, M, y);
    int m = 0;
    for (auto& i : x)
    {
        for (auto& j: y)
        {
            if (i.second.second < j.second.first || i.second.first > j.second.second)
            {
                m = max(i.first + j.first, m);
            }
        }
    }
    return m;
}
