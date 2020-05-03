bool buddyStrings(string A, string B) {
    int len_a = A.size();
    int len_b = B.size();
    if (len_a != len_b) return false;

    vector<int> diff;
    for (int i = 0; i < len_a; ++i)
    {
        if (A[i] != B[i])
        {
            diff.push_back(A[i]);
            diff.push_back(B[i]);
            if (diff.size() > 4) return false;
        }
    }
    if (diff.size() == 0)
    {
        unordered_map<int, int> flag;
        for (int i = 0; i < len_a; ++i)
        {
            ++flag[A[i]];
            if (flag[A[i]] > 1) return true;
        }
    }
    if (diff.size() == 4)
    {
        return diff[0] == diff[3] && diff[1] == diff[2];
    }
    return false;
}
