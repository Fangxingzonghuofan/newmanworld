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
    int minimumTotal(vector<vector<int>>& triangle) {
        int size=triangle.size();
        vector<int> pathMin(size,0);
        pathMin[0]=triangle[0][0];
        int y=0;
        for (int i = 1; i <size; i++)
        {
            if(triangle[i][y]>triangle[i][y+1]){
                pathMin[i]=triangle[i][y+1]+pathMin[i-1];
                y++;
            }
            else{
                pathMin[i]+=triangle[i][y]+pathMin[i-1];
            }
        }
        return pathMin[size-1];
    }
};//变傻了，这一题要用动态规划的，但我用的是贪心算法，傻傻分不清...
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size=triangle.size();
        vector<int> dp=triangle.back();
        for (int i = size-1; i>0; i--)
        {
            for (int j = 0; j <i; j++)
            {
                dp[j]=min(dp[j],dp[j+1])+triangle[i-1][j];
            }
        }
        return dp[0];
    }
};//思路很不错，从底部到顶部，时间和空间复杂度都做到了最优