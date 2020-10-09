
class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> votes;
        int max_voter = persons.front();
        votes[max_voter] = 0;
        for (int i =0; i<times.size(); ++i)
        {
            votes[persons[i]]++;
            if (max_voter != persons[i])
            {
                if (votes[max_voter] <= votes[persons[i]]) max_voter = persons[i];
            }
            fm.push_back({ times[i], max_voter });
        }
    }

    int q(int t) {
        if (fm.size() <= 0) return 0;
        int mi = 0;
        int ma = fm.size()-1;
        if (t < fm[0].first) return 0;
        if (t > fm.back().first) return fm.back().second;
        while (ma - mi > 1)
        {
            int m = (mi + ma) / 2;
            if (fm[m].first > t) ma = m;
            if (fm[m].first < t) mi = m;
            if (fm[m].first == t) return fm[m].second;
        }
        if (fm[ma].first == t) return fm[ma].second;
        return fm[mi].second;
    }
private:

    vector<pair<int, int>> fm;
};
/**
