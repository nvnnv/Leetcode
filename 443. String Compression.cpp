int compress(vector<char>& chars) {
    int len_char = chars.size();
    if (len_char == 0) return 0;
    int num = 0;
    for (auto i = chars.begin()+1; i != chars.end();)
    {
        if (*i == *(i - 1))
        {
            ++num;
            i = chars.erase(i);
        }
        else
        {
            ++num;
            if (num == 1)
            {
                ++i;
            }
            else
            {
                int c = 0;
                while (num)
                {
                    i = chars.insert(i, (num % 10) + 48);
                    num /= 10;
                    ++c;
                }
                i += c+1;
            }
            num = 0;
        }
    }
        ++num;
    if(num != 1)
    {
        auto i = chars.end();
        while (num)
        {
            i = chars.insert(i, (num % 10) + 48);
            num /= 10;
        }
    }
    return chars.size();
}
