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
    int maxSubarraySumCircular(vector<int>& nums) {
        int mincurSum=nums[0];
        int maxcurSum=nums[0];
        int maxSum=nums[0];
        int minSum=nums[0];
        int sum=nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            maxcurSum=max(nums[i],maxcurSum+nums[i]);
            mincurSum=min(nums[i],mincurSum+nums[i]);
            maxSum=max(maxSum,maxcurSum);
            minSum=min(minSum,mincurSum);
            sum+=nums[i];
        }
        int maxSum2=sum-minSum;
        if(maxSum2==0) return maxSum;
        return max(maxSum2,maxSum);
    }
};//这一题思路简直难死了我靠，好巧的思路，总和减最小和为跨界（个数不为零的）最大和