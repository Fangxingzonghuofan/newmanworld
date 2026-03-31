#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int low=1,high=x;
        while (low<=high)
        {
            int mid=low+(high-low)/2;//防止溢出
            if(mid==x/mid) return mid;//这里也是防止溢出
            if(mid>x/mid) high=mid-1;
            else low=mid+1;
        }
        return high;
    }
};