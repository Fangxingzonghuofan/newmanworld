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
    vector<string> summaryRanges(vector<int>& nums) {
        int i=0;
        vector<string> res;
        while(i<nums.size()){
            int tmp=i;
            while(tmp<nums.size()-1&&nums[tmp+1]==nums[tmp]+1){
                tmp++;
            }
            if(tmp==i) res.emplace_back(to_string(nums[i]));
            else {
                string s=to_string(nums[i]);
                s+=string("->")+to_string(nums[tmp]);//改用append函数更便捷可控,优于+=，因为会自动扩容
                res.push_back(s);
            }
            /*对22到26行进行改写
            string s=to_string(nums[i]);
            if(tmp>i){
            s.append("->");
            s.append(to_string(nums[tmp]));
            } 
            res.push_back(s);
            改写之后更便于阅读且更高效
            */
            i=tmp+1;
        }
        return res;
    }
};