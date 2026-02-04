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