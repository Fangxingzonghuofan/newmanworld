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
    int maxSubArray(vector<int>& nums) {
        int curSum=nums[0];
        int maxSum=nums[0];
        for (int i = 1; i <nums.size(); i++)
        {
            curSum=max(nums[i],nums[i]+curSum);
            maxSum=max(maxSum,curSum);
        }//这一题思路取名为忘本，前路对自己有益就带上，有害就丢掉再起灶炉，又叫识时务者为俊杰
        return maxSum;
    }
};