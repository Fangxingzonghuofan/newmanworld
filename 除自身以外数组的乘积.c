int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize=numsSize;
    returnSize=(int *)malloc(sizeof(int *)*numsSize);
    returnSize[0]=1;
    for (int  i = 1; i <numsSize; i++)
    {
        returnSize[i]=returnSize[i-1]*nums[i-1];    
    }
    int R=1;
    for (int i = numsSize-1; i >=0;--i)
    {
        returnSize[i]=returnSize[i]*R;
        R=R*nums[i];
    }
    return returnSize;
}