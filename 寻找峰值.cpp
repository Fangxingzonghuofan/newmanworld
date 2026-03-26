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
    int findPeakElement(vector<int>& nums) {
        int size=nums.size();
        int low=0;
        int high=size-1;
        while (low<high)
        {
            int mid=(low+high)/2;
            if(nums[mid]<nums[mid+1]){
                low=mid+1;
            }
            else high=mid;
        }
        return low;
    }
};