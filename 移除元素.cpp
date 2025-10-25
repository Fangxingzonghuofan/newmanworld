int removeElement(int* nums, int numsSize, int val) {
    //使用快慢指针法
/* int slow=0;
for(int fast=0;fast<numsSize;++fast){
    if(nums[fast]!=val)
{    nums[slow++]=nums[fast];
}
}
return slow;
    */
    int K=0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i]!=val)
        {
           nums[K]=nums[i];
           K++;
        }
        
    }
    return K;
}