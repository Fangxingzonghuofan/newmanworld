/*void rotate(int* nums, int numsSize, int k) {
    int *Nums=(int *)malloc(k*sizeof(int ));
    k=k%numsSize;
    for (int i=numsSize-k; i <numsSize; i++)
    {
        Nums[i-numsSize+k]=nums[i];
    }
    for (int i=numsSize-k-1;i>=0;i--)
    {
        nums[i+k]=nums[i];
    }
    for (int i = 0; i < k; i++)
    {
        nums[i]=Nums[i];
    }
    free (Nums);
    return;   
}*/
//推荐解法：数组翻转可实现原地变换
void swap(int* a, int* b) {
    int t = *a;
    *a = *b, *b = t;
}

void reverse(int* nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start += 1;
        end -= 1;
    }
}

void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}