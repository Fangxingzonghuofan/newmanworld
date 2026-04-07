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
    int lengthOfLIS(vector<int>& nums) {
        int size=nums.size();
        vector<int>dp(size,1);
        int maxLen=1;
        for (int i = 0; i < size; i++)
        {
           for (int j = 0; j <i; j++)
           {
            if(nums[j]<nums[i]) dp[i]=max(dp[i],dp[j]+1);
           }
           maxLen=max(maxLen,dp[i]);
        }
        return maxLen;
    }
};//我的思路是正常思路，能解出来但是时间开销很大，下面尝试贪心➕二分方法
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for(int num:nums){
            auto it=lower_bound(tails.begin(),tails.end(),num);
            if(it==tails.end()) tails.push_back(num);
            else *it=num;//此处lower_bound的用法也十分重要
            /*它的作用是在有序数组中从左至右找到第一个大于num的数并返回该数的迭代器指针*/
        }
        return tails.size();
    }
};//非常惊艳的做法，简直让我惊为天人！！！
