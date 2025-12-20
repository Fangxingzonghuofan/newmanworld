//不是哥们儿，看到就觉得有意思，这题太好玩了
int trap(int* height, int heightSize) {
    //第一步先求最高的柱子最小坐标
    int rain=0;
    int miniMax=0;
    for (int i = 1; i < heightSize; i++)
    {
        if (height[miniMax]<height[i])
        {
            miniMax=i;
        }
        
    }
    int pre=0;
    for (int i = 0; i <miniMax; i++)
    {
        if (height[i]>pre)
        {
            pre=height[i];
        }
        if (pre>height[i])
        {
            rain+=pre-height[i];
        }
    }
    pre=0;
    for (int  i = heightSize-1; i >miniMax; i--)
    {
        if (height[i]>pre)
        {
            pre=height[i];
        }
        if (pre>height[i])
        {
            rain+=pre-height[i];
        }
    }    
    return rain;
}//哈哈哈哈哈哈还是困难级别的题目，一下子就写出来了，拿捏拿捏