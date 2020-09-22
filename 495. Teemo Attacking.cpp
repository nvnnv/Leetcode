int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    if(timeSeries.size() == 0) return 0;
    int _d = duration - 1;
    int s = duration;
    int end = timeSeries[0] + _d;
    for (int i = 1; i < timeSeries.size(); i++)
    {
        int t = timeSeries[i] + _d;
        if (end >= timeSeries[i])
        {
            s += (t - end);  
        }
        else
        {
            s += duration;
        }
        end =t ;
    }
    return s;
}
