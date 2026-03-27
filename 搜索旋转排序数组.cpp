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
    int search(vector<int>& nums, int target) {
        int size=nums.size();
        int low=0,high=size-1;
        int sorted=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>=nums[low]){
                if(nums[mid]>target&&nums[low]<=target){
                    high=mid-1;
                }
                else low=mid+1;
            }
            else if(target>nums[mid]&&target<=nums[high]) low=mid+1;
            else high=mid-1;
       }
       return -1;
    }
};