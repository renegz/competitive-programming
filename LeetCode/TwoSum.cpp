#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) { 
        map<int, int> dp;
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++)
        {
            int val = target - nums[i];
            if(dp.find(val) != dp.end()){
                res.push_back(dp[val]);
                res.push_back(i);
                break;
            }
            dp[nums[i]] = i;
        }

        return res;
    }
};        