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
    int minDistance(string word1, string word2) {
        int r = word1.size(), l = word2.size();

        vector<vector<int>> dp(r+1, vector<int>(l+1));

        for (int i = 0; i <= r; i++) dp[i][0] = i;
        for (int j = 0; j <= l; j++) dp[0][j] = j;

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= l; j++) {

                int del = dp[i-1][j] + 1;
                int ins = dp[i][j-1] + 1;
                int rep = dp[i-1][j-1] + (word1[i-1] != word2[j-1]);

                dp[i][j] = min(del, min(ins, rep));
            }
        }

        return dp[r][l];
    }
};//思路依旧比较难，不太会的样子哎，简化成一维空间
class Solution {
public:
    int minDistance(string word1, string word2) {
        int r = word1.size(), l = word2.size();

        vector<int> dp(l + 1);

        for (int j = 0; j <= l; j++) dp[j] = j;

        for (int i = 1; i <= r; i++) {

            int prev = dp[0];  // 关键：dp[i-1][0]

            dp[0] = i;

            for (int j = 1; j <= l; j++) {

                int temp = dp[j];  // 保存 dp[i-1][j]

                int del = dp[j] + 1;      // dp[i-1][j]
                int ins = dp[j-1] + 1;    // dp[i][j-1]
                int rep = prev + (word1[i-1] != word2[j-1]); // dp[i-1][j-1]

                dp[j] = min({del, ins, rep});

                prev = temp;  // 更新左上角
            }
        }

        return dp[l];
    }
};