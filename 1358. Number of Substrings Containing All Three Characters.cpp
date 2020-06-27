int numberOfSubstrings(string s) {
    int ans = 0;
    int couple = 0;
    int pos[3]; // the index of nearest a, b or c away from the current pos
    pos[0] = -1; pos[1] = -1; pos[2] = -1;
    for (int i = 0; i < s.size(); ++i)
    {
        int temp = 0;
        switch (s[i])
        {
        case 'a':
            temp = min(pos[1], pos[2]);
            if (temp >= 0)
            {
                ans += temp + 1;
            }
            break;
        case 'b':
            temp = min(pos[0], pos[2]);
            if (temp >= 0)
            {
                ans += temp + 1;
            }
            break;
        case 'c':
            temp = min(pos[1], pos[0]);
            if (temp >= 0)
            {
                ans += temp + 1;
            }
            break;
        default :
            break;
        }
        pos[s[i] - 97] = i;
    }
    return ans;;
}
