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
    void backtrack(vector<int>& candidates,int target,vector<int>& ans,int start){
        for (int i = start; i <candidates.size(); i++)
        {
            if(target==0){
                res.push_back(ans);
                return;
            }
            if (candidates[i]<=target)
            {
                ans.push_back(candidates[i]);
                backtrack(candidates,target-candidates[i],ans,i);
                ans.pop_back();
            }
            if(candidates[i]>target) break;
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,ans,0);
        return res;
    }
};