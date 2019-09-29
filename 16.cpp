class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    auto len = nums.size();
    if(len <= 3)
    {
        int sum = 0 ;
        for(auto i = 0 ; i< len; i++)
        {
            sum += nums[i];
        }
        return sum;
    }
    sort(nums.begin(), nums.end());
    int j , k;
    int x, y, z;
    int temp;
    int ans = nums[0] + nums[1] + nums[2];

    for(auto i = 0 ;i<= len-2;i++)
    {
        x = nums[i];
        j = i+1;
        k = len -1;
        while(j < k)
        {
            y = nums[j];
            z = nums[k];
            temp = x+y+z;
            if(abs(temp - target) < abs(ans - target))
            {
                ans = temp;
            }

                if(temp > target)
                {
                    k--;
                } else if(temp < target)
                {
                    j++;
                }
                else
                {
                    return temp;
                }
        }
        while(x == nums[i+1]) i++;
    }
    return  ans;
    }
};
