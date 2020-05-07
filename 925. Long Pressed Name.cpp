bool isLongPressedName(string name, string typed) {
    int j = 0;
    for (int i = 0; i < name.size(); ++i)
    {
        int x = i;
        while (x < name.size() && name[x] == name[i])
        {
            ++x;
        }
        int k = j;
        while (k < typed.size() && typed[k] == name[i])
        {
            ++k;
        }
        if (k - j + 1 < x - i + 1) return false;
        j = k;
        i = x-1;
    }
    if (j != typed.size()) return false;
    return true;
}
