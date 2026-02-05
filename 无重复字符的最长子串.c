int lengthOfLongestSubstring(char* s) {
    int len=strlen(s);
    int maxlen=0;
    for(int l=0,r=0;r<len;r++)
    {
        for (int j=l;j<r;j++)
        {
            if (s[j]==s[r])
            {
                l=j+1;
            }
        }
        int capacity=r-l+1;
        if (capacity>maxlen)
        {
            maxlen=capacity;
        }
    }
    return maxlen;
}//我写的普通解法，下面给出最优解（由ai提示思路）
int lengthOfLongestSubstring(char* s) {
    int len=strlen(s);
    int maxlen=0;
    int last[256];
    for (int i = 0; i < 256; i++) {
        last[i] = -1;
    }
    for(int l=0,r=0;r<len;r++)
    {
        if (last[s[r]] >= l)
        {
            l = last[s[r]] + 1;
        }
        last[s[r]]=r;
        int capacity=r-l+1;
        if (capacity>maxlen)
        {
            maxlen=capacity;
        }
    }
    return maxlen;
}