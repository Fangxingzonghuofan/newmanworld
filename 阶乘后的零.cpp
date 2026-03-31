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
    int trailingZeroes(int n) {
        //这一题本质是在数5以及倍数（次方数）的个数，因为尾随零的产生必定是2*5的结果
        //而二的倍数绝对比五的倍数多，所以只需要计算五的倍数即可
        return n/5+n/25+n/125+n/625+n/3125;//在这里解释一下，25，125等等是5的二次方和三次方
        //他们必然会产生两个零及三个零（倍数二的比五的多得多），所以在后面加上补差，高次方也相等，而题目给的n<=10^4，故只加到3125即可

    }
};