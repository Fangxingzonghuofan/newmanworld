int removeDuplicates(int* nums, int numsSize) {
    if (numsSize<=2)
    {
        return numsSize;
    }
    int slow=2,fast=2;
    int k=2;
    while (fast<numsSize)
    {
        if (!(nums[fast]==nums[slow-1]&&nums[fast]==nums[slow-2]))
        {
            nums[slow++]=nums[fast];
            k++;
        }
        fast++;
    }
    return k;
}