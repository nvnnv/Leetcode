// dp  20ms
void xxoo(vector<vector<int>>& mat, vector<vector<int>>& dp, int k, int i, int j)
{
    int sum = 0;
    int i_left = 0, i_right = 0, j_left = 0, j_right = 0;
    int row_size = mat[i].size();
    int column_size = mat.size();
    i_left = i - k >= 0 ? i - k : 0; i_right = i + k < column_size ? i + k : column_size - 1;
    j_left = j - k >= 0 ? j - k : 0; j_right = j + k < row_size ? j + k : row_size - 1;
    // top
    for (int x = i_left; x < i; ++x)
    {
        for (int y = j_left; y <= j_right; ++y)
        {
            sum += mat[x][y];
        }
    }
    // bottom
    for (int x = i + 1; x <= i_right; ++x)
    {
        for (int y = j_left; y <= j_right; ++y)
        {
            sum += mat[x][y];
        }
    }
    // left
    // right
    for (int y = j_left; y <= j_right; ++y)
    {
        sum += mat[i][y];
    }
    dp[i][j] = sum;
}
void xoleft(vector<vector<int>>& mat, vector<vector<int>>& dp, int k, int i, int j)
{
    int prev_ = dp[i][j - 1];
    int i_left = 0, i_right = 0;
    i_left = i - k >= 0 ? i - k : 0; i_right = i + k < mat.size() ? i + k : mat.size() - 1;
    if (j - k - 1 >= 0)
    {
        int sub = 0;
        for (int x = i_left; x <= i_right; ++x)
        {
            sub += mat[x][j-k-1];
        }
        prev_ -= sub;
    }
    if (j + k < mat[i].size())
    {
        int plus = 0;
        for (int x = i_left; x <= i_right; ++x)
        {
            plus += mat[x][j + k];
        }
        prev_ += plus;
    }
    dp[i][j] = prev_;
}
void xodown(vector<vector<int>>& mat, vector<vector<int>>& dp, int k, int i, int j)
{
    int prev_ = dp[i - 1][j];
    int j_left = 0, j_right = 0;
    j_left = j - k >= 0 ? j - k : 0; j_right = j + k < mat[i].size() ? j + k : mat[i].size() - 1;
    if (i - k - 1 >= 0)
    {
        int sub = 0;
        for (int y = j_left; y <= j_right; ++y)
        {
            sub += mat[i - k - 1][y];
        }
        prev_ -= sub;
    }
    if (i + k < mat.size())
    {
        int plus = 0;
        for (int y = j_left; y <= j_right; ++y)
        {
            plus += mat[i + k][y];
        }
        prev_ += plus;
    }
    dp[i][j] = prev_;
}
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
    vector<vector<int>> dp;
    // init
    dp = mat;
    for (int i = 0; i < mat.size(); ++i)
    {   
        if (i == 0)
        {
            xxoo(mat, dp, K, i, 0);
        }
        else
        {
            xodown(mat, dp, K, i, 0);
        }
        for (int j = 1; j < mat[i].size(); ++j)
        {
            xoleft(mat, dp, K, i, j);
        }
    }
    return dp;
}


// violent loop 762ms
void xxoo(vector<vector<int>>& mat, vector<vector<int>>& dp, int k, int i, int j)
{
    int sum = 0;
    int i_left = 0, i_right = 0, j_left = 0, j_right = 0;
    int row_size = mat[i].size();
    int column_size = mat.size();
    i_left = i - k >= 0 ? i - k : 0; i_right = i + k < column_size ? i + k : column_size - 1;
    j_left = j - k >= 0 ? j - k : 0; j_right = j + k < row_size ? j + k : row_size - 1;
    // top
    for (int x = i_left; x < i; ++x)
    {
        for (int y = j_left; y <= j_right; ++y)
        {
            sum += mat[x][y];
        }
    }
    // bottom
    for (int x = i + 1; x <= i_right; ++x)
    {
        for (int y = j_left; y <= j_right; ++y)
        {
            sum += mat[x][y];
        }
    }
    // left
    // right
    for (int y = j_left; y <= j_right; ++y)
    {
        sum += mat[i][y];
    }
    dp[i][j] = sum;
}
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
    vector<vector<int>> dp;
    // init
    dp = mat;
    for (int i = 0; i < mat.size(); ++i)
    {   
        if (i == 0)
        {
            
        }
        else
        {

        }
        for (int j = 0; j < mat[i].size(); ++j)
        {
            xxoo(mat, dp, K, i, j);
        }
    }
    return dp;
}
