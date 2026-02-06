#define maxwordsnum 5000
#define maxwordlen 30
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    *returnSize=0;
    int len=strlen(s);
    int wordlen=strlen(words[0]);
    int biglen=wordlen*wordsSize;
    int *res=(int *)malloc(len*sizeof(int));
    char diffword[maxwordsnum][maxwordlen];
    int diffnum[maxwordsnum];
    int diff=0;
    for (int  i = 0; i < wordsSize; i++)
    {
        int found=0;
        for (int j = 0; j < diff; j++)
        {
            if (strcmp(words[i],diffword[j])==0)
            {
                diffnum[j]++;
                found=1;
                break;
            }   
        }
        if (!found)
        {
            strcpy(diffword[diff],words[i]);
            diffnum[diff++]=1;
        }
    }
    for (int  i = 0; i <wordlen; i++)
    {
        int left=i,right=i;
        int windowdiffnum[maxwordsnum];
        memcpy(windowdiffnum,diffnum,diff*sizeof(int));
        while (right+wordlen<=len)
        {
            char tmp[maxwordlen+1];
            strncpy(tmp,s+right,wordlen);
            tmp[wordlen]='\0';
            int found=0;
            for (int j = 0; j < diff; j++)
            {
                if (strcmp(tmp, diffword[j]) == 0)
{
    found = 1;
    windowdiffnum[j]--;

    // ⭐ 补上超量收缩
    while (windowdiffnum[j] < 0)
    {
        char leftWord[maxwordlen+1];
        strncpy(leftWord, s + left, wordlen);
        leftWord[wordlen] = '\0';

        for (int k = 0; k < diff; k++)
        {
            if (strcmp(leftWord, diffword[k]) == 0)
            {
                windowdiffnum[k]++;
                break;
            }
        }
        left += wordlen;
    }
    break;
}

                
            }
            if(found==0){
                    left=wordlen+right;
                    right=left;
                    memcpy(windowdiffnum,diffnum,diff*sizeof(int));
                    continue;
                }
            right+=wordlen;
            if (right-left==biglen)
            {
                res[*returnSize]=left;
                (*returnSize)++;
            }
            
        }
        
    }
    return res;
}