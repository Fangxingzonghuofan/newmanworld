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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res;
        int high=nums.size()-1;
        int low=0;
        while (low<=high)
        {
            int mid=(high+low)/2;
            if(nums[mid]==target)
            {
                int temp=mid;
                while (mid>0&&nums[mid-1]==target)
                {
                    mid--;
                } 
                res.push_back(mid);
                mid=temp;
                while (mid<nums.size()-1&&nums[mid+1]==target)
                {
                    mid++;   
                }
                res.push_back(mid);
                return res;
            }
            if(target<nums[mid]) high=mid-1;
            else low=mid+1;
        }
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
};//这其实并不是真正意义上的O(log2n)，会退化为O(n),下面给出更标准的写法，找边界
class Solution {
public:
    int leftBound(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = nums.size();
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int rightBound(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = nums.size();
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans - 1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = leftBound(nums, target);
        int right = rightBound(nums, target);

        if (left <= right && right < nums.size() && nums[left] == target) {
            return {left, right};
        }
        return {-1, -1};
    }
};