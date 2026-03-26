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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int c=matrix[0].size();
        int size=matrix.size()*c-1;
        int low=0,high=size;
        while (low<=high)
        {
            int mid=(low+high)/2;
            int row=mid/c;
            int col=mid%c;
            if(matrix[row][col]==target){
                return true;
            }
            else if(target<matrix[row][col])
            {
                high=mid-1;
            }
            else low=mid+1;
        }
        return false;
    }
};