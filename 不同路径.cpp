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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r=obstacleGrid.size(),l=obstacleGrid[0].size();
        vector<vector<int>> dp(r,vector<int>(l));
        dp[0][0]=1;
        if(obstacleGrid[0][0]==1) 
        {
            return 0;
        }
        for (int i = 1; i <l; i++)
        {
            if(obstacleGrid[0][i]==1) dp[0][i]=0;
            else dp[0][i]=dp[0][i-1];
        }
        
        for (int i = 1; i <r; i++)
        {
            if(obstacleGrid[i][0]==1) dp[i][0]=0;
            else dp[i][0]=dp[i-1][0];
            for (int j = 1; j <l; j++)
            {
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[r-1][l-1];
    }
};//依旧是空间复杂度可以压缩为一维的，现在我将尝试
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r=obstacleGrid.size(),l=obstacleGrid[0].size();
        vector<int> dp(l);
        dp[0]=1;
        if(obstacleGrid[0][0]==1) 
        {
            return 0;
        }
        for (int i = 1; i <l; i++)
        {
            if(obstacleGrid[0][i]==1) dp[i]=0;
            else dp[i]=dp[i-1];
        }
        
        for (int i = 1; i <r; i++)
        {
            if(obstacleGrid[i][0]==1) dp[0]=0;
            for (int j = 1; j <l; j++)
            {
                if(obstacleGrid[i][j]==1) dp[j]=0;
                else dp[j]=dp[j]+dp[j-1];
            }
        }
        return dp[l-1];
    }
};
//太强了我是小天才来的吧，一维空间复杂度的算法居然只看了一次就学会了！！！虽然是在二维的基础上改的，但是也很棒了！！！