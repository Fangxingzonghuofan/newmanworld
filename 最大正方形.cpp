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
    int maximalSquare(vector<vector<char>>& matrix) {
        int r=matrix.size();
        int l=matrix[0].size();
        int Max=0;
        for (int i = 0; i <r; i++)
        {
            Max=max(Max,matrix[i][0]-'0');
        }
        for (int j = 1;j <l; j++)
        {
            Max=max(Max,matrix[0][j]-'0');
        }
        for (int i = 1; i < r; i++)
        {
            for (int j = 1; j < l; j++)
            {
                if(matrix[i][j]=='1')
                {
                    if(matrix[i-1][j]!='0'&&matrix[i][j-1]!='0'&&matrix[i-1][j-1]!='0')
                    {
                        matrix[i][j]=min(matrix[i-1][j]-'0',min(matrix[i-1][j-1]-'0',matrix[i][j-1]-'0'))+1+'0';
                    }
                    Max=max(Max,matrix[i][j]-'0');
                }
            }
        }
        return Max*Max;
    }
};//这里都是我自己写的，思路基本正确，但是可以进行优化，下面给出优化版本
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r=matrix.size();
        int l=matrix[0].size();
        int Max=0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 1; j < l; j++)
            {
                if(matrix[i][j]=='1')
                {
                    if(i==0||j==0) Max=max(Max,matrix[i][j]-'0');
                    else if(i>0&&j>0){
                        matrix[i][j]=min(matrix[i-1][j]-'0',min(matrix[i-1][j-1]-'0',matrix[i][j-1]-'0'))+1+'0';
                    }
                    Max=max(Max,matrix[i][j]-'0');
                }
            }
        }
        return Max*Max;
    }
};//修改后依旧无法正确运行，原因是char溢出，下面使用int存储
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int l = matrix[0].size();
        
        vector<vector<int>> dp(r, vector<int>(l, 0));
        int Max = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < l; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min({
                            dp[i-1][j],
                            dp[i][j-1],
                            dp[i-1][j-1]
                        }) + 1;

                    Max = max(Max, dp[i][j]);
                }
            }
        }
        return Max * Max;
    }
};//这一题空间复杂度还可以优化为O(n)
