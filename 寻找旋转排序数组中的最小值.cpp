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
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int Min=nums[0];
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[low]<=nums[mid]){
                Min=min(Min,nums[low]);
                low=mid+1;
            }
            else {
                Min=min(Min,nums[mid]);
                high=mid-1;
            }
        }
        return Min;
    }
};//我的写法如上，但是可以更加优化，可以去掉Min变量，ai给的更简洁写法如下：
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            // 如果已经有序，直接返回
            if (nums[low] < nums[high]) {
                return nums[low];
            }

            int mid = low + (high - low) / 2;

            if (nums[mid] >= nums[low]) {
                // 左边有序，最小值在右边
                low = mid + 1;
            } else {
                // 最小值在左边（包含 mid）
                high = mid;
            }
        }
        return nums[low];
    }
};