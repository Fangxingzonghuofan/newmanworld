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
    int searchInsert(vector<int>& nums, int target) {
        int size=nums.size();
        int low=0,high=size-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(target<nums[mid])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};
//以上是循环的方法写二分查找，较为简单，我一开始的思路是使用递归来写，下面进行完善
class Solution {
    int search(vector<int> &nums,int target,int left,int right){
        if(left>right){
            return left;
        }
        int mid=(right+left)/2;
        if(nums[mid]==target) return mid;
        if(target<nums[mid])
        {
            return  search(nums,target,left,mid-1);
        }
        else{
            return search(nums,target,mid+1,right);
        }
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        return search(nums,target,0,nums.size()-1);
    }
};