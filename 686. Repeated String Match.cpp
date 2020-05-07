//12ms
int repeatedStringMatch(string A, string B) {
    int len_a = A.size();
    int len_b = B.size();

    int repeated = len_b / len_a + (len_b%len_a ? 1 : 0);
    string new_a = "";
    for (int i = 0; i < repeated; ++i) new_a += A;
    if (new_a.find(B, 0)!= -1) return repeated;
    new_a += A;
    ++repeated;
    if (new_a.find(B, 0) != -1) return repeated;
    return -1;
}
// 1700ms

int repeatedStringMatch(string A, string B) {
    int len_a = A.size();
    int len_b = B.size();

    int repeated = len_b / len_a + 1;
    string new_a = A;
    for (int i = 0; i < repeated; ++i) new_a += A;
    len_a = new_a.size();
    for (int i = 0; i <= len_a - len_b; ++i)
    {
        int j = 0;
        while (i < len_a && j < len_b && new_a[i] == B[j])
        {
            ++i;
            ++j;
        }
        if (j== len_b)
        {
            int k = len_a / (repeated + 1);
            return i / k + (i% k ? 1 : 0) < repeated+1 ? i / k + (i % k ? 1 : 0) : repeated+1;
        }
        if(j) i-=j;
    }
    return -1;
}
