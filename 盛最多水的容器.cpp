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
//二刷，补充c++版本
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=height.size();
        int low=0,high=l-1;
        int capa=0;
        int maxCapability=capa;
        while(low<high){
            capa=min(height[low],height[high])*(high-low);
            maxCapability=maxCapability>capa?maxCapability:capa;
            if(height[low]<height[high]) ++low;
            else --high;
        }/*注意：当height[low]==height[high]时
        ++low和--right都可以
        这是因为，无论哪一种选择，改变后的capa一定小于之前的capa
        要对结果产生影响的话（新的capa大于max或者旧的capa），一定是
        中间出现了两个都大于height[low]和height[high]的数，
        因此移动哪一边的指针都没关系
        */
        return maxCapability;
    }
};
