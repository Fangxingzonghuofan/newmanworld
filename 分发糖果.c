/*int candy(int* ratings, int ratingsSize) {

        int all=0;
        int nums=1;
    for (int  i = 0; i < ratingsSize-1; i++)
    {
        if (ratings[i]<ratings[i+1])
        {
            all+=nums;
            nums++;
        }
        if (ratings[i]==ratings[i+1])
        {
            all+=nums;
            nums=1;
        }
        
        if(ratings[i]>ratings[i+1]){
            int j=i;
            while(j + 1 < ratingsSize &&ratings[j]>ratings[j+1]){
                j++;
            }
            all+=(j-i+2)*(j-i+1)/2-1;
            i=j-1;
            nums=1;
        }
    }
    if (ratings[ratingsSize-1]>ratings[ratingsSize-2])
    {
        all+=nums;
    }
    else{
        all++;
    }
    return all;
}*/
//燃尽了兄弟们，这一题写了好几天一直写不出来我要死了直接上答案吧
int candy(int* ratings, int ratingsSize) {
    int ret = 1;
    int inc = 1, dec = 0, pre = 1;
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] >= ratings[i - 1]) {
            dec = 0;
            pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
            ret += pre;
            inc = pre;
        } else {
            dec++;
            if (dec == inc) {
                dec++;
            }
            ret += dec;
            pre = 1;
        }
    }
    return ret;
}
//兄弟们这就是我想写出来的效果哭了，还得是官方厉害