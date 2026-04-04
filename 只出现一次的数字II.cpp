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
public://这一题思路还挺难的，要用什么三进制，门电路，分享一个leetcode上大佬的做法：数位相加取余3
    int singleNumber(vector<int>& nums) {
        vector<int> cnt(32,0);
        int size=nums.size();
        for (int i = 0; i <size; i++)
        {
            for (int j = 0; j < 32; j++)
            {
                cnt[j]+=(nums[i]>>j)&1;
            }
        }
        int res=0;
        for (int i = 0; i <32; i++)
        {
            res+=(cnt[i]%3)<<i;
        }
        return res;
    }
};//再分享一个三进制无敌高深的做法，反正这个做法太高级了我是不会的
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};