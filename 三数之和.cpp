#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b){
    return *(int *)a-*(int *)b;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int **result=(int **)malloc(numsSize*numsSize*sizeof(int *));
    *returnColumnSizes=(int *)malloc(numsSize*numsSize*sizeof(int));
    if (result==NULL||*returnColumnSizes==NULL)
    {
        free(result);
        free(*returnColumnSizes);
        return NULL;
    }
    *returnSize=0;
    for (int i = 0; i <numsSize-2; i++)
    {
        if (i>0&&nums[i]==nums[i-1])
        {
            continue;
        }
        int left=i+1;
        int right=numsSize-1;
        while(left<right)
        {
            int sum=nums[i]+nums[left]+nums[right];
            if (sum==0)
            {
                result[*returnSize]=(int *)malloc(3*sizeof(int));
                result[*returnSize][0]=nums[i];
                result[*returnSize][1]=nums[left];
                result[*returnSize][2]=nums[right];
                (*returnColumnSizes)[*returnSize]=3;
                (*returnSize)++;
                while (left<right&&nums[left]==nums[left+1])
                {
                    left++;
                }
                while (left<right&&nums[right]==nums[right-1])
                {
                    right--;
                }
                left++;
                right--;
                
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    return result;
    
}
//二刷了，补一个c++的写法
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int s=nums.size();
        vector<vector<int>> res;
        if(s<3) return res;
        sort(nums.begin(),nums.end());
        for(int first=0;first<s;++first){
            if(first>0&&nums[first]==nums[first-1])
            {
                continue;
            }
            int third=s-1;
            int target=-nums[first];
            for(int second=first+1;second<s;++second)
            {
                if(second>first+1&&nums[second]==nums[second-1])
                {
                continue;
                }
                while(second<third&&nums[second]+nums[third]>target)
                {
                    --third;
                }
                if(second==third) break;
                if(nums[second]+nums[third]==target)
                {
                    res.push_back({nums[first],nums[second],nums[third]});
                }
            }
        } 
        return res;
    }
};
