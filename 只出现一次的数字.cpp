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
    int singleNumber(vector<int>& nums) {
        int size=nums.size();
        for (int i = 1; i <size; i++)
        {
            nums[0]^=nums[i];
        }
        return nums[0];
    }
};
//交换律：a ^ b ^ c <=> a ^ c ^ b

//任何数于0异或为任何数 0 ^ n => n

//相同的数异或为0: n ^ n => 0
//思路好牛逼我靠，简单题还不会可以确证智障了，没错我就是
