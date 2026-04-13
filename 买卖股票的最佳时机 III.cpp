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
    int maxProfit(vector<int>& prices) {
        int l=prices.size();
        vector<int> max_sec_profit(l,0);
        vector<int> max_fir_profit(l,0);
        int minprices=prices[0];
        int maxDiff=0;
        for (int i = 0; i < l; i++)
        {
            if(prices[i]-minprices>maxDiff) maxDiff=prices[i]-minprices;
            if(prices[i]<minprices) minprices=prices[i];
            max_fir_profit[i]=maxDiff;
            int max=prices[i];
            for (int j =i+1 ; j < l; j++)
            {
                if(prices[j]>max) max=prices[j];
            }
            max_sec_profit[i]=max-prices[i];
        }
        int Max=0;
        for (int i = 0; i <l; i++)
        {
            Max=max(max_sec_profit[i]+max_fir_profit[i],Max);
        }
        return Max;
    }
};//写了一晚上的屎山代码，最后还超出时间限制（但是思路其实是对的，只是想不到动态规划的解法而已），没招了，下面进行更改
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<int> left(n, 0);   // 第i天之前最多赚多少
        vector<int> right(n, 0);  // 第i天之后最多赚多少

        // 👉 第一遍：从左往右（第一笔交易）
        int minPrice = prices[0];
        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            left[i] = max(left[i-1], prices[i] - minPrice);
        }

        // 👉 第二遍：从右往左（第二笔交易）
        int maxPrice = prices[n-1];
        for (int i = n-2; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            right[i] = max(right[i+1], maxPrice - prices[i]);
        }

        // 👉 合并
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, left[i] + right[i]);
        }

        return ans;
    }
};