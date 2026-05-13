int minSubArrayLen(int target, int* nums, int numsSize) {
    int sum=0;
    int left=0,right;
    int minlen=numsSize+1;
    for(right=0;right<numsSize;right++)
    {
        sum+=nums[right];
        while (sum>=target)
        {
            int len=right-left+1;
            if (len<minlen)
            {
                minlen=len;
            }
            sum-=nums[left];
            left++;
        }
    }
    return minlen==numsSize+1?0:minlen;
}
//二刷，补充c++解法，有思路就简单，滑动窗口法与双指针法类似，也要注意区分
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s=nums.size();
        int left=0,right=0;
        int minLen=INT_MAX;
        int sum=0;
        while(right<s){
            if(sum<target) sum+=nums[right++];
            while(sum>=target){
                minLen=min(minLen,right-left);
                sum-=nums[left++];
            }
        }
        return minLen==INT_MAX?0:minLen;
    }
};


