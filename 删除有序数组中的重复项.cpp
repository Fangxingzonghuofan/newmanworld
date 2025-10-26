int removeDuplicates(int* nums, int numsSize) {
    int k=1;

        int slow,fast;//快慢指针
        slow=fast=0;
        while (fast<numsSize-1)
        {
          if (nums[++fast]!=nums[fast-1])
        {
           k++;
           nums[++slow]=nums[fast];
        }
        }
        return k;
    
}