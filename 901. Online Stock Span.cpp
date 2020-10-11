class StockSpanner {
public:
    StockSpanner() {

    }

    int next(int price) {
        if (v.size() == 0)
        {
            v.push_back({ price, 1 });
            return 1;
        }
        int x = 1;
        while (!v.empty() && v.back().first <= price)
        {
            x += v.back().second;
            v.pop_back();
        }
        v.push_back({ price, x });
        return x;
    }
private:
    vector<pair<int, int>> v;
};
