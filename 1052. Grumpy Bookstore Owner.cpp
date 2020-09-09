int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    int sum_X = 0;
    int left = 0;
    for (int i = 0; i < X; ++i)
    {
        sum_X += customers[i];
    }
    for (int i = X; i < customers.size(); ++i)
    {
        if (grumpy[i] == 0) left += customers[i];
    }
    int aim_X = max(sum_X + left, aim_X);
    for (int i = X; i < customers.size(); ++i)
    {
        sum_X += (customers[i] - customers[i - X]);
        if (grumpy[i] == 0) left -= customers[i];
        if (grumpy[i - X] == 0) left += customers[i - X];
        aim_X = max(sum_X + left, aim_X);
    }
    return aim_X;
}
