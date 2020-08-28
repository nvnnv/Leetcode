vector<int> pancakeSort(vector<int>& A) {
    auto s = A;
    sort(s.begin(), s.end());
    int lastP = A.size()-1;
    vector<int> x;
    while(lastP > 0)
    {
        int iMax = s.back();
        s.pop_back();
        int iMaxP = 0;
        for (int j = 0; j < A.size(); ++j)
        {
            if (A[j] == iMax)
            {
                iMaxP = j; break;
            }
        }
        if (lastP == iMaxP)
        {
            --lastP;  continue;
        }
        reverse(A.begin(), A.begin() + iMaxP + 1);
        x.push_back(iMaxP + 1);
        reverse(A.begin(), A.begin() + lastP + 1);
        x.push_back(lastP + 1);
        --lastP;
    }
    return x;
}
