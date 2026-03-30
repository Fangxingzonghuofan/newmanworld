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
    bool isPalindrome(int x) {
        string num=to_string(x);
        int l=0,r=num.size()-1;
        while (l<r)
        {
            if(num[l]!=num[r]) return false;
            else 
            {
                l++;
                r--;
            }
        }
        return true;
    }
};//此方法较慢，尝试进阶：进阶：你能不将整数转为字符串来解决这个问题吗？
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        vector<int> units; 
        while(x>0){
            units.emplace_back(x%10);
            x=x/10;
        }
        int n=units.size();
        for (int i = 0; i <n/2; i++)
        {
            if(units[i]!=units[n-i-1]) return false;
        }
        return true;
    }
};//两种方法效率都不高，下面给出标准解法：
class Solution {
public:
    bool isPalindrome(int x) {
        // 负数 or 结尾是0但不是0本身
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reverted = 0;

        while (x > reverted) {
            reverted = reverted * 10 + x % 10;
            x /= 10;
        }

        return x == reverted || x == reverted / 10;//处理奇数位和偶数位
    }
};