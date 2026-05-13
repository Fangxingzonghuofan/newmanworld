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
//二刷这一题，给出c++解法，还是用c++好写，这是我写出来的双百写法，和当初比起来进步很大呀，滑动窗口用暴力解法也可以，更优解法是使用last数组记录每个字符上次出现位置（我的解法）
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.size();
        int last[256]={0};
        int left=0,right=0;
        int maxLen=0;
        while(right<len){
            if(last[s[right]]==0)
            {
                maxLen=max(maxLen,right-left+1);
                last[s[right++]]=1;
                continue;
            }
            while(last[s[right]]==1){
                last[s[left++]]=0;
            }
        }
        return maxLen;
    }
};
