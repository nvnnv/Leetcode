vector<int> pathInZigZagTree(int label) {
    if (label == 1) return { 1 };
    int n = 2;
    int rowMax = 3;
    int rowMin = 2;
    while (rowMax < label)
    {
        /*
        if (n % 2 == 0)
        {
            for (int i = rowMax; i >= rowMin; --i)
            {
                v.push_back(i);
            }
        }
        else
        {
            for (int i = rowMin; i <= rowMax; ++i)
            {
                v.push_back(i);
            }
        }
        n++;
        rowMax = 2 * rowMax + 1;
        rowMax = 2 * rowMin;
        */
        n++;
        rowMax = 2 * rowMax + 1;
        rowMin = 2 * rowMin;
    }
    vector<int> trace = {label};
    int nRow =0;
    if (n % 2 == 0)
    {
        nRow = rowMax - label + 1;
    }
    else
    {
        nRow = label - rowMin + 1;
    }
    while (n != 2)
    {
        rowMax = (rowMax - 1) / 2;
        rowMin = rowMin / 2;
        n--;
        int nRow1 = (nRow + 1) / 2;
        if (n % 2 == 0)
        {
            label = rowMax - (nRow1 - 1);
            trace.push_back(label);
            nRow = rowMax - label + 1;
        }
        else
        {
            label = rowMin + (nRow1 - 1);
            trace.push_back(label);
            nRow = label - rowMin + 1;
        }
    }
    trace.push_back(1);
    reverse(trace.begin(), trace.end());
    return trace;
}
