bool isPalindrome(string s) {

    string new_s = "";
    for (auto c : s)
    {
        if (c >= 48 && c <= 57)
        {
            new_s.push_back(c);
        }
        if (c >= 65 && c <= 90)
        {
            new_s.push_back(c + 32);
        }
        if (c >= 97 && c <= 122)
        {
            new_s.push_back(c);
        }
    }

    int L = 0;
    int R = new_s.size() - 1;
    while (L <= R)
    {
        if (new_s[L] == new_s[R])
        {
            ++L;
            --R;
        }
        else
        {
            return false;
        }
    }
    return true;
}
