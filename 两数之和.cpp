#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashT;
        for (int t=0;t<nums.size();++t)
        {
            auto it=target-nums[t];
            if (hashT.count(it))
            {
                return {hashT[it],t};
            }
            hashT[nums[t]]=t;//hashT.emplace(nums[t],t);
        }
        return {};
    }
};
/*| 函数           | 用在谁     | 作用     |
| ------------ | ------- | ------ |
| push_back    | vector  | 插入已有对象 |
| emplace_back | vector  | 原地构造   |
| insert       | set/map | 插入对象   |
| emplace      | set/map | 原地构造   |*/
