bool canJump(int* nums, int numsSize) {
    /*if (numsSize==1)
    {
        return 1;
    }
    
    for (int i = numsSize-2; i>=0; i--)
    {
        if (nums[i]>=numsSize-i-1&&canJump(nums,i+1))
        {
            return 1;
        }
    }
    return 0;*/
    if (numsSize <= 1) return 1;
    int maxindex=nums[0];
    for (int  i = 0; i <=maxindex; i++)
    {
        if (i+nums[i]>maxindex)
        {
            maxindex=i+nums[i];
        }
        if (maxindex>=numsSize-1)
        {
        return 1;
        }
    }
    return 0;
}