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
    int rob(vector<int>& nums) {
        int size=nums.size();
        int memony2,memony1,tmp;
        memony2=nums[0];
        if(size==1) return memony2;
        memony1=max(memony2,nums[1]);
        for (int i = 2; i < size; i++)
        {
            tmp=memony1;
            memony1=max(memony1,memony2+nums[i]);
            memony2=tmp;
        }
        return memony1;
    }
};//和上一次差不多的思路嘿嘿嘿，不过改用了常数级内存空间