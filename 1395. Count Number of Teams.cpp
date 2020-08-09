// 8ms  n^2
int numTeams(vector<int>& rating) {
    int x = 0;
    for (int i = 1; i < rating.size()-1; ++i)
    {
        int ma1 = 0;
        int mi1 = 0;
        for (int j = 0; j < i; ++j)
        {
            if (rating[i] > rating[j]) ++ma1;
            if (rating[i] < rating[j]) ++mi1;
        }
        int ma2 = 0;
        int mi2 = 0;
        for (int j = i + 1; j < rating.size(); ++j)
        {
            if (rating[i] > rating[j]) ++mi2;
            if (rating[i] < rating[j]) ++ma2;
        }
        x += (ma2 * ma1) + (mi1 * mi2);
    }
    return x;
}

// 136ms n^3
int numTeams(vector<int>& rating) {
    int x = 0;
    for (int i = 0; i < rating.size(); ++i)
    {
        for (int j = i + 1; j < rating.size(); ++j)
        {
            for (int k = j + 1; k < rating.size(); ++k)
            {
                if (rating[i] > rating[j] && rating[j] > rating[k]) ++x;
                if (rating[i] < rating[j] && rating[j] < rating[k]) ++x;
            }
        }
    }
    return x;
}
