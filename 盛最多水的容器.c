int maxArea(int* height, int heightSize) {
    int i=0,j=heightSize-1;
    int Maxsize=0;
    int capacity=0;
    while (i<j)
    {
        capacity=(j-i)*(height[i]<height[j]?height[i]:height[j]);
        if (Maxsize<capacity)
        {
            Maxsize=capacity;
        }
        if (height[i]<=height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return Maxsize;
}