//我的做法将此题想复杂了，其实这一题不需要用到递归算法，直接使用更简单高效的倒循环即可
int jump(int* nums, int numsSize) {
    int minindex;
    int i;
    if (numsSize==1)
    {
        return 0;
    }
    
    for (i = numsSize-1; i >=0; --i)
    {
        if (i+nums[i]>=numsSize-1)
        {
            minindex=i;
        }
        
    }
    return 1+jump(nums,minindex+1);
}//以上是我的解法，下面是官方更简单的解法
int jump(int* nums, int numsSize) {
    int position = numsSize - 1;
    int steps = 0;
    while (position > 0) {
        for (int i = 0; i < position; i++) {
            if (i + nums[i] >= position) {
                position = i;
                steps++;
                break;
            }
        }
    }
    return steps;
}
//上面两种方法时间复杂度都为O(2),下面是复杂度更低的解法，正向查找最大位置
int jump(int* nums, int numsSize) {
    int maxPos = 0, end = 0, steps = 0;
    for (int i = 0; i < numsSize - 1; ++i) {
        if (maxPos >= i) {
            maxPos = (maxPos > i + nums[i]) ? maxPos : i + nums[i];
            if (i == end) {
                end = maxPos;
                ++steps;
            }
        }
    }
    return steps;
}