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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> setTable;
        for (int &i:nums)
        {
            setTable.emplace(i);
        }//这一段可以用unordered_set<int> setTable(nums.begin(),nums.end());代替
        int longest=0;
        for (int i:setTable)
        {
            if (!setTable.count(i-1))
            {
                int current=i;
                int length=1;
                while (setTable.count(current+1))
                {
                    current++;
                    length++;
                }
                longest=max(longest,length);
            }
        }
        return longest;
    }
};