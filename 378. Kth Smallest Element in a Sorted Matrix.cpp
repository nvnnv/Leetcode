int HowBigK(vector<vector<int>>& matrix, int aim)
{
    int k = 0;
    for (int i = 0; i < matrix.size(); ++i)
    {
        int j = matrix[i].size() - 1;
        while (j >= 0 && matrix[i][j] > aim ) --j;
        k += j + 1;
    }
    return k;
}
int kthSmallest(vector<vector<int>>& matrix, int k) {
    if (matrix.size() == 0) return 0;
    if (matrix[0].size() == 0) return 0;
    int head = matrix.front().front();
    int foot = matrix.back().back();
    while (head < foot)
    {
        int m = head + (foot - head) / 2;
        int _k = HowBigK(matrix, m);
        if (_k < k) head = m + 1;
        else foot = m;
    }
    return head;
}


int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (auto& v : matrix)
    {
        for (auto& i : v)
        {
            q.push(i);
        }
    }
    while (k > 1)
    {
        q.pop();
        --k;
    }
    return q.top();
}
