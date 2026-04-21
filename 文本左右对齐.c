//累死我了写不来这个真的，放弃放弃以后再战。
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    int capacity=16;
    int linecount=0;
    char **result=malloc(capacity*sizeof(char*));
    for (int  i = 0, lettercount=0,linewordcount=0,linehead=0; i <wordsSize; i++)
    {
        lettercount+=strlen(words[i]);
        if (lettercount<=maxWidth)
        {
            linewordcount++;
            lettercount++;
        }
        else
        {
            int space;
            space=maxWidth-lettercount+strlen(words[i])+1;
            int spacearr=space/(linewordcount-1);
            int spacespecial=space%(linewordcount-1);
           if (linecount == capacity) {
    capacity *= 2;
    char** tmp = realloc(result, capacity * sizeof(char*));
    if (!tmp) return NULL;
    result = tmp;
}

result[linecount] = malloc(maxWidth + 1);

            result[linecount][0]='\0';
            strcat(result[linecount],words[linehead]);
            for(int j=1;j<linewordcount;j++)
            {
                if (j<=spacespecial)
                {
                    for (int t = 0; t < spacearr+1; t++)
                    {
                        strcat(result[linecount]," ");
                    }
                    
                }
                else 
                {
                    for (int t = 0; t < spacearr; t++)
                    {
                        strcat(result[linecount]," ");
                    }
                }
                strcat(result[linecount],words[linehead+j]);
            }
            result[linecount++][maxWidth]='\0';
            linehead=i;
            i--;
            linewordcount=0;
            lettercount=0;
        }
    }
    *returnSize = linecount;
     return result;


}