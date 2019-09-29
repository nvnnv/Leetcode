class Solution {
public:
    // 111ms AC
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            if (target < 0) break;
            int L = i + 1, R = nums.size() - 1;
            while (L < R) {
                int sum = nums[L] + nums[R];
                if (sum < target)   L++;
                else if (sum > target)  R--;
                else {
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[L];
                    triplet[2] = nums[R];
                    res.push_back(triplet);

                    while (L < R && nums[L] == triplet[1])   L++;
                    while (L < R && nums[R] == triplet[2])   R--;
                }

            }
            while (i < nums.size() && nums[i] == nums[i+1]) i++;
        }
        return res;  
    }
};

class Solution {
public:
    // 890ms AC
    vector<vector<int>> threeSum(vector<int>& nums) {
    auto len = nums.size();
    vector<vector<int>> ans;
    if(len < 3)
    {
        return ans;
    }
    sort(nums.begin(), nums.end());
    set<int> s1, s2, s3;
    int j , k;
    int x, y, z;
    for(auto i = 0 ;i<= len-3;i++)
    {
        x = nums[i];
        if(s1.count(x) != 0) continue;
        j = i+1;
        k = len -1;
        while(j < k)
        {
            y = nums[j];
            z = nums[k];
            if(s2.count(y) != 0 && s3.count(z) != 0)
            {
                j++;
                k--;
                continue;
            }
            if(y + z > -x)
            {
                k--;
                s3.insert(z);
            }
            else if(y +z < -x)
            {
                j++;
                s2.insert(y);
            }
            else
            {
                vector<int> a;
                a.push_back(x);
                a.push_back(y);
                a.push_back(z);
                ans.push_back(a);
                j++;
                k--;
                s2.insert(y);
                s3.insert(z);
            }
        }
        s2.clear();
        s3.clear();
        s1.insert(x);
    }
    return ans;
    }
};
