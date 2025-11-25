int hIndex(int* citations, int citationsSize) {
    for (int i = 0,temp; i < citationsSize; i++)
    {
        for (int  j = citationsSize-1; j >i; --j)
        {
            if (citations[j-1]<citations[j])
            {
                temp=citations[j-1];
                citations[j-1]=citations[j];
                citations[j]=temp;
            }
        }
    }
    int H=0;//目前讨论通过的论文数
    for (int i = 0; i < citationsSize; ++i)
    {
        if (citations[i]>=H+1)
        {
        H++;
        }
        else{
            break;    
        }
        
    }
    return H;
}