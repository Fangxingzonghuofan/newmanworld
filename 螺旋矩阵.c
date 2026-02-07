#include <stdio.h>
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int fangxiang=0;
    int up=0,low=matrixSize-1,left=0,right=(*matrixColSize)-1;
    int i=0,j=0;
    int nums=0;
    *returnSize=matrixSize*(*matrixColSize);
    int *res=(int *)malloc((*returnSize)*sizeof(int));
    while(up<=low&&left<=right)
    {
    if(fangxiang==0)
    {for (j=left;j<=right;j++)
    {
        res[nums++]=matrix[up][j];
    }
    up++;
    fangxiang=(fangxiang+1)%4;}
    
    else if(fangxiang==1)
    {for(i=up;i<=low;i++)
    {
        res[nums++]=matrix[i][right];
    }
    right--;
    fangxiang=(fangxiang+1)%4;}


    else if(fangxiang==2)
    {for(j=right;j>=left;j--)
    {
        res[nums++]=matrix[low][j];
    }
    low--;
    fangxiang=(fangxiang+1)%4;}


    else if(fangxiang==3)
    {for(i=low;i>=up;i--)
    {
        res[nums++]=matrix[i][left];
    }
    left++;
    fangxiang=(fangxiang+1)%4;
}}
    
    
    return res;
}