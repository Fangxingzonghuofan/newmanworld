char* reverseWords(char* s) {
    int len=strlen(s);
    char *cs=(char*)malloc((len+1)*sizeof(char));
    cs[0]='\0';
    int worldlen=0;
    int flag=1;
    for (int i = len-1; i>=-1; i--)
    {
        if (i==-1||s[i]==' ')
        {
            if (worldlen!=0)
            {
                if (flag==0)
                {
                    strcat(cs, " ");
                }
                
                strncat(cs,s+i+1,worldlen);
                flag=0; 
            }
            
            worldlen=0;
        }
        else{
        worldlen++;}
    }
    return cs;
}