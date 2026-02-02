bool isSubsequence(char* s, char* t) {
    int i=0,j=0;
    while(s[i]!='\0'&&t[j]!='\0')
    {
        if (s[i]==t[j])
        {
         i++;   
        }
        j++;
    }
    return s[i]=='\0';
}//较为简单，思路清晰即可（不建议使用strlen函数，可以直接使用字符串数组末尾有'\0'的性质）