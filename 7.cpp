// 2 years ago completed
int reverse(int x) {
    long long temp = 0;
    long long ans = 0;
    while(x != 0)
    {
        temp = x%10;
        x /= 10;
        ans = ans ? ans*10+temp : temp;
    }
    if(ans > 2147483647 || ans < -2147483648) return 0;
    return (int)ans;
}
