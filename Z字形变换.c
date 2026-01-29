char* convert(char* s, int numRows) {
    int len=strlen(s);
    int c=numRows*2-2;
    int t=-1;
    if (numRows == 1||numRows >= len) return s;
    char *S=(char *)malloc((len+1)*sizeof(char));
    for (int  i = 0; i <numRows ; i++)
    {
        for (int j = 0;i+j*c<len; j++)
        {
            if(i==0||i==numRows-1)
            {
                S[++t]=s[i+j*c];
            }
            else{
                S[++t]=s[i+j*c];
                if (-i+(j+1)*c<len)
                {
                    S[++t]=s[-i+(j+1)*c];
                }
            }
        }
    }
    S[t+1]='\0';
    return S;
}//在时间和空间的角度上看我这个已经算最优的解法了
//但从算法的容易理解的方面看，模拟行走法更为巧妙。