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
    bool isInterleave(string s1, string s2, string s3) {
        int r=s1.length(),l=s2.length();
        vector<vector<bool>> dp(r+1,vector<bool>(l+1,false));
        dp[0][0]=true;
        if(r+l!=s3.length()){
            return false;
        }
        for (int j= 1; j <= l; j++)
        {
            dp[0][j]=dp[0][j-1]&&s2[j-1]==s3[j-1];
        }
        for (int i = 1; i <=r; i++)
        {
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        }
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= l; j++)
            {
                dp[i][j] =(dp[i-1][j] && s1[i-1] == s3[i+j-1])||(dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        return dp[r][l];
    }
};//空间压缩优化算法：
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int r = s1.size(), l = s2.size();
        if (r + l != s3.size()) return false;

        vector<bool> dp(l + 1, false);

        // 初始化：只用 s2
        dp[0] = true;
        for (int j = 1; j <= l; j++) {
            dp[j] = dp[j-1] && s2[j-1] == s3[j-1];
        }

        for (int i = 1; i <= r; i++) {
            dp[0] = dp[0] && s1[i-1] == s3[i-1];

            for (int j = 1; j <= l; j++) {
                dp[j] =
                    (dp[j] && s2[j-1] == s3[i+j-1]) ||
                    (dp[j-1] && s1[i-1] == s3[i+j-1]);
            }
        }

        return dp[l];
    }
};