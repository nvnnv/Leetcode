// from one odd position to any odd position, cost is 0, even position is same
// so, will all odd position move to 2N+1th position and all even position move to 2N position.
// then, the problem is simplified as min(number of odd positions, number of even positions)
int minCostToMoveChips(vector<int>& position) {
    int o = 0;
    int even = 0;
    for (auto i : position)
    {
        if (i % 2) ++o;
        else ++even;
    }
    return min(o, even);
}
