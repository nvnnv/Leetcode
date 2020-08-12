bool isIdealPermutation(vector<int>& A) {
    int i = 1;
    int j = 1;
    while (i < A.size())
    {
        if (A[i] != j && A[i - 1] != j)
        {
            if (i == A.size() - 1) return false;
            else if (A[i + 1] != j) return false;
        }
        ++j;
        ++i;
    }
    if(A[0] != 0 && A[1] != 0) return false;
    return true;
}
