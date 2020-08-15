void getDiagonal(int x, int y, vector<int>& dia, vector<vector<int>>& m)
{
    while (x < m.size() && y < m[0].size())
    {
        dia.push_back(m[x][y]);
        ++x;
        ++y;
    }
}
void setDiagonal(vector<int>& dia, vector<vector<int>>& m, int x, int y)
{
    for (int i = 0; i < dia.size(); ++i)
    {
        m[x][y] = dia[i];
        ++x;
        ++y;
    }
}
vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    // right-up
    for (int i = 0; i < mat[0].size(); ++i)
    {
        vector<int> dia;
        getDiagonal(0, i, dia, mat);
        sort(dia.begin(), dia.end());
        setDiagonal(dia, mat, 0, i);
    }
    // left-bottom
    for (int i = 1; i < mat.size(); ++i)
    {
        vector<int> dia;
        getDiagonal(i, 0, dia, mat);
        sort(dia.begin(), dia.end());
        setDiagonal(dia, mat, i, 0);
    }
    return mat;
}
