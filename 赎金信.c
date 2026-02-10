#include <stdbool.h>
bool canConstruct(char* ransomNote, char* magazine) {
    int lenr=strlen(ransomNote);
    int lenm=strlen(magazine);
    int *used=(int *)malloc(lenm*sizeof(int));
    int found=0;
    for (int i = 0; i < lenr; i++)
    {
        found=0;
        for (int j = 0; j <lenm; j++)
        {
            if (ransomNote[i]==magazine[j]&&used[j]!=1)
            {
                used[j]=1;
                found=1;
                break;
            }
        }
        if (found==0)
        {
            return false;
        }
    }
    return true;
}//以上是最简单的暴力解法，下面使用哈希表来解决这个问题
bool canConstruct(char* ransomNote, char* magazine) {
    int cnt[26]={0};
    for (int i = 0;magazine[i]; i++)
    {
        cnt[magazine[i]-'a']++;
    }
    for (int i = 0; ransomNote[i];i++)
    {
        if (--cnt[ransomNote[i]-'a']<0)
        {

            return false;
        }
        
    }
    return true;
    
}