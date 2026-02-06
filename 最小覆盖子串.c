char* minWindow(char* s, char* t) {
    int slen=strlen(s);
    int tlen=strlen(t);
    int minlen=slen+1;
    char *diffletter=(char *)malloc(tlen*sizeof(char));
    int *diff=(int *)malloc(tlen*sizeof(int));
    memset(diff, 0, tlen*sizeof(int));
    int cnt=0;
    for (int i = 0; i < tlen; i++)
    {
        int found=0;
        for (int j = 0; j<cnt; j++)
        {
            if (diffletter[j]==t[i])
            {
                found=1;
                diff[j]++;
            } 
        }
        if (found==0)
        {
            diffletter[cnt]=t[i];
            diff[cnt]=1;
            cnt++;
        }
        
    }
    int left=0,right=0;
    int found=0;
    int maxleft=0;
    while (left<=right&&right<slen)
    {
        for (int i = 0; i < cnt; i++)
        {
            if (s[right]==diffletter[i])
            {
                diff[i]--;
                break;
            }
        }
        for (int i = 0; i < cnt; i++)
        {
            if (diff[i]>0)
            {
                found=1;
                break;
            }
        }
        while(found==0&&left<=right)
        {
            int capacity=right-left+1;
            if (minlen>capacity)
            {
                minlen=capacity;
                maxleft=left;
            }
            for (int i = 0; i < cnt; i++)
        {
            if (s[left]==diffletter[i])
            {
                diff[i]++;
                break;
            }
        }
        for (int i = 0; i < cnt; i++)
        {
            if (diff[i]>0)
            {
                found=1;
                break;
            }
        }
        left++;
        }
        right++;
        found=0;
    }
    if (minlen > slen) return ""; // 没有合法窗口
    char *res=(char*)malloc((minlen+1)*sizeof(char));
    res[0]='\0';
    strncpy(res,s+maxleft,minlen);
    res[minlen]='\0';
    return res;
}//我个人根据上一题30：串联所有单词的子串的思路写出来的算法，并非最优算法仍然具有改进空间