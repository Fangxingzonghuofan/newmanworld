bool isPalindrome(char* s) {
    int len=strlen(s);
    int pre=0;
    int p=len-1;
    while (pre<p)
    {
        if (s[pre]<97||s[pre]>122)
        {
                while (pre<p&&(s[pre]<48||(s[pre]>57&&s[pre]<65)||(s[pre]>90&&s[pre]<97)||s[pre]>122))
                {
                    pre++;
                }
                    
            if (s[pre]>=65&&s[pre]<=90)
            {
                s[pre]=s[pre]+32;
            }      
        }
        if (s[p]<97||s[p]>122)
        {
                while  (pre<p&&(s[p]<48||(s[p]>57&&s[p]<65)||(s[p]>90&&s[p]<97)||s[p]>122))
                {
                    p--;
                }
            if (s[p]>=65&&s[p]<=90)
            {
                s[p]=s[p]+32;
            }       
        }
        if (s[p]!=s[pre])
        {
            return 0;
        }
        pre++;
        p--;
    }
    return 1;
}//解答起来确实很简单，但是可读性不好，下面给出更好的方法
/*int isValid(char c) {
    return (c >= '0' && c <= '9') ||
           (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z');
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') return c + 32;
    return c;
}
bool isPalindrome(char* s) {
while (l < r) {
    while (l < r && !isValid(s[l])) l++;
    while (l < r && !isValid(s[r])) r--;

    if (toLower(s[l]) != toLower(s[r])) return false;

    l++;
    r--;
}
return 1;
}
*/