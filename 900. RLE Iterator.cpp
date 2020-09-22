class RLEIterator {
public:
    RLEIterator(vector<int>& A) {
        B = A;
    }
    
    int next(int n) {
        b_i += n;
        while(sum < b_i && cur < B.size())
        {
            sum += B[cur];
            cur += 2;
        }

        if(sum < b_i) return -1;
        return B[cur-1];
    }
private:
    vector<int> B;
    long long b_i = 0;
    long long cur = 0;
    long long sum = 0;
};

    RLEIterator(vector<int>& A) {
        B = A;
    }
    
    int next(int n) {
        b_i = n;
        if(b_i > B[cur] && cur == (B.size()-2)) return -1;
        while(sum < b_i && cur < B.size())
        {
            sum += B[cur];
            if(sum < b_i) B[cur] = 0;
            cur += 2;
        }
        if(cur -2 >0)
        {
            B[cur-2] -= b_i;
        }
        return B[cur-1];
    }
