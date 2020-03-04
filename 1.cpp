// 2 years ago completed
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int len = nums.size();
        int a, b;
        bool c = false;
        for (int i = 0; i < len; ++i) {
            a = nums.at(i);
            for (int j = 0; j < len; ++j) {
                if(i == j)
                {
                    continue;
                }
                b = nums.at(j);
                if((a + b) == target)
                {
                    c = true;
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
            if(c)
            {
                break;
            }
        }
        return res;
    }
