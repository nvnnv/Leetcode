class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        if (!fm.count(key))
        {
            vector<pair<int, string>> v;
            fm.insert({ key, v });
        }
        fm[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (!fm.count(key)) return "";
        auto& v = fm[key];
        int mi = v.front().first;
        int ma = v.back().first;
        if (mi > timestamp) return "";
        if (ma < timestamp) return v.back().second;
        int i = 0;
        int j = v.size() - 1;
        while (i <= j && v[j].first > timestamp)
        {
            int m = (i + j) / 2;
            if (v[m].first > timestamp) j = m - 1;
            if (v[m].first < timestamp) i = m + 1;
            if (v[m].first == timestamp)
            {
                return v[m].second;
            }
        }
        return v[j].second;
    }

private:
    unordered_map<string, vector<pair<int, string>>> fm;
};
