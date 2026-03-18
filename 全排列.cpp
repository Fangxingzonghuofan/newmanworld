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
    vector<vector<int>>res;
    vector<bool> vis;
    void backtrack(vector<int>& nums,vector<int>&ans,vector<bool>&vis){
        if (ans.size()==nums.size())
        {
            res.push_back(ans);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                ans.push_back(nums[i]);
                vis[i]=true;
            backtrack(nums,ans,vis);
            vis[i]=false;
            ans.pop_back();
            }
        } 
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> exit(nums.begin(),nums.end());
        vector<int> ans;
        vis.resize(nums.size(),false);
        backtrack(nums,ans,vis);
        return res;
    }
};