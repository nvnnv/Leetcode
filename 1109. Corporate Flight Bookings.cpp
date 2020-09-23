vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> x(n+1, 0);
    for (int i = 0; i < bookings.size(); ++i)
    {
        auto& v = bookings[i];
        x[v[0]-1] += v[2];
        x[v[1]] += -v[2];
    }
    for (int i = 1; i < n; ++i)
    {
        x[i] += x[i - 1] ;
    }
    vector<int> a;
    a.insert(a.begin(), x.begin(), x.end() - 1);
    return a;
}   
