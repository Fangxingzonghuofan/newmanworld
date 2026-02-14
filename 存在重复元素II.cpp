#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>
#include <cmath>

using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (mp.count(nums[i])&&i-mp[nums[i]]<=k)
            {
                return true;
            }
            mp[nums[i]]=i;//注意不能使用mp.emplace(nums[i],i);
        }
        return false;
    }
};