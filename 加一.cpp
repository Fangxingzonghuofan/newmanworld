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
    vector<int> plusOne(vector<int>& digits) {
        int plusone=0;
        int n=digits.size();
        digits[--n]++;
        if(digits[n]<=9) return digits;
        else
        {
            plusone=1;
            digits[n]=0;
            n--;
            while (plusone==1&&n>=0)
            {
                digits[n]++;
                if(digits[n]<=9) plusone=0;
                else digits[n]=0;
                n--; 
            }
            if(plusone==1) digits.insert(digits.begin(),1);
        }
        return digits;
    }
};//写法逻辑较为复杂，下面给出更简单的做法
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i]++;

            if (digits[i] <= 9) {
                return digits;  // 没有进位，直接返回
            }

            digits[i] = 0;  // 有进位，继续往前
        }

        // 全是 9 的情况
        digits.insert(digits.begin(), 1);
        return digits;
    }
};