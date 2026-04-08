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
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size(),l=grid[0].size();
        vector<vector<int>> dp(r,vector<int>(l));//重点！！！！如何初始化多维vector数组！！
        for (int i = 0; i <r; i++)
        {
            for (int j = 0; j <l; j++)
            {
                if(j-1<0&&i-1>=0) dp[i][j]=dp[i-1][j]+grid[i][j];
                else if(j-1>=0&&i-1<0) dp[i][j]=dp[i][j-1]+grid[i][j];
                else if(j-1>=0&&i-1>=0) dp[i][j]=min(dp[i][j-1],dp[i-1][j])+grid[i][j];
                else dp[i][j]=grid[i][j];
            }
        }
        return dp[r-1][l-1];
    }
};//下面是将空间复杂度O(n^2)优化为O(n)的解法
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size(), l = grid[0].size();

        vector<int> dp(l);

        // 初始化第一行
        dp[0] = grid[0][0];
        for (int j = 1; j < l; j++)
            dp[j] = dp[j-1] + grid[0][j];

        // 从第二行开始
        for (int i = 1; i < r; i++) {
            dp[0] += grid[i][0];  // 第一列

            for (int j = 1; j < l; j++) {
                dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
            }
        }

        return dp[l-1];
    }
};//这个算法真的很好！！！大脑褶皱瞬间被抚平的想法！！