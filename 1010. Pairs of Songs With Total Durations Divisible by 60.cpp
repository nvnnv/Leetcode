// 56ms
int numPairsDivisibleBy60(vector<int>& time) {
    int len_time = time.size();
    vector<int> ans(60, 0);
    int ans1 = 0;
    for (auto i : time)
    {
        int xo = i % 60;
        if (xo == 0)
        {
            ans1 += ans[xo];
        }
        else
        {
            ans1 += ans[60 - xo];
        }
        ++ans[xo];
    }
    return ans1;
}
// 76ms
int numPairsDivisibleBy60(vector<int>& time) {
    int len_time = time.size();
    for (auto& i : time)
    {
        i = i % 60;
    }
    unordered_map<int, int> flag;
    for (auto i : time)
    {
        ++flag[i];
    }
    int ans = 0;
    int ans1 = 0;
    for (auto p : flag)
    {
        if (p.first == 0)
        {
            ans += (p.second - 1) * p.second / 2;
            continue;
        }
        int temp = 60 - p.first;
        if (flag.find(temp) == flag.end()) continue;
        if (temp == p.first)
        {
            ans += (p.second - 1) * p.second / 2;
        }
        else
        {
            ans1 += p.second * flag[temp];
        }
    }
    return ans + ans1/2;
}
// 348ms
int numPairsDivisibleBy60(vector<int>& time) {
    int len_time = time.size();
    for (int i = 0; i < len_time; ++i)
    {
        time[i] %= 60;
    }
    sort(time.begin(), time.end());
    int temp = 0;
    int temp1;
    int temp2;
    int l = 0;
    int r = 0;
    int ans = 0;
    int ans1 = 0;
    int ans2 = 0;
    for (int i = 0; i < time.size(); ++i)
    {
        if (time[i] == 0)
        {
            ans2++;
            continue;
        }
        temp = 60 - time[i];
        if (temp < time[i])
        {
            l = 0;
            r = i - 1;
        }
        else if (temp > time[i])
        {
            l = i + 1;
            r = len_time-1;
        }
        else
        {
            temp1 = 1;
            r = i + 1;
            while (r < len_time && time[r] == temp) ++temp1, ++r;
            l = i - 1;
            while (l >= 0 && time[l] == temp) ++temp1, --l;
            ans1 += (temp1 - 1) * temp1 / 2;
            i = r - 1;
            continue;
        }
        while (l <= r)
        {
            temp1 = (l + r)/ 2;
            if (time[temp1] == temp)
            {
                ++ans;
                temp2 = temp1;
                ++temp1;
                while (temp1 < len_time && time[temp1++] == temp) ++ans;
                --temp2;
                while (temp2 >= 0 && time[temp2--] == temp) ++ans;
                break;
            }
            else if (time[temp1] > temp)
            {
                r = temp1 - 1;
            }
            else
            {
                l = temp1 + 1;
            }
        }
    }
    return ans/2 + ans1 + (ans2-1)*ans2/2;
}
