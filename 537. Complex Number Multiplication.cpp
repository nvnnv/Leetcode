class Solution {
public:
void getNumsFromComplex(string& a, int* x)
{
    int i = 0;
    int k = 0;
    int f = 1;
    while (a[i] != 'i')
    {
        if (a[i] == '-') f = -1, ++i;
        if (a[i] == '+')
        {
            if(a[i+1] == '-') f = -1, ++i,++i;
            else f = 1, ++i;
        }
        while (a[i] <= 58 && a[i] >= 48)
        {
            x[k] = x[k] * 10 + a[i] - 48;
            ++i;
        }
        x[k] *= f;
        ++k;
    }
}
string complexNumberMultiply(string a, string b) {
    int x[2] = { 0,0 };
    int y[2] = { 0,0 };
    getNumsFromComplex(a, x);
    getNumsFromComplex(b, y);

    int new_a = x[0]*y[0] + x[1] * y[1]*-1;
    int new_b = x[0]*y[1] + y[0]*x[1];
    return to_string(new_a) + "+" + to_string(new_b) + "i";
}
};
