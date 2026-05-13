#include <stdio.h>
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *index=(int *)malloc(2*sizeof(int));
    if (index==NULL)
    {
        printf("malloc errror\n");
        *returnSize=0;
        return NULL;
    }
    
    int i=0,j=numbersSize-1;
    while(i<j)
    {
        int t=numbers[i]+numbers[j];
        if (t<target)
        {
            i++;
        }
        if (t>target)
        {
            j--;
        }
        if (t==target)
        {
            index[0]=i+1;
            index[1]=j+1;
            *returnSize=2;
            return index;
        }        
    }
    *returnSize=0;
    free(index);
    return NULL;
}//较简单，学习一下代码规范如malloc检查是否分配成功，未查询到正确结果及时free并return NULL
//二刷，补一份c++代码
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int right=numbers.size()-1;
        int left=0;
        while(left<right){
            if(numbers[left]+numbers[right]==target) return {left+1,right+1};
            else if(numbers[left]+numbers[right]<target) left++;
            else right--;
        }
       return {-1,-1};
    }
};
