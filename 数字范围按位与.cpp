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
class Solution {//ok啊这一题也是完全炸天的思路好吧
public:
    int rangeBitwiseAnd(int left, int right) {
        int diff=0;
        while (left!=right)
        {
            left>>=1;
            right>>=1;
            diff++;
        }
        return left<<=diff;
    }//因为是按位与，所以只要有一位出现零后面相同的位都是零，又因为是连续整数，所以只有相同的高位不一定是零，因此这一题思路是求最大公共前位
};