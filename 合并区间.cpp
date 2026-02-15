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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        /*for(const auto &i:intervals){
            int diff=0;
            for(auto &j:res){
                if(i[0]<=j[1]&&i[1]>j[1]){
                    j[1]=i[1];
                    diff=1;
                    break;
                }
                else if(i[1]<=j[1]){
                    diff=1;
                    break;
                }
            }
            if(diff==0){
                res.push_back(i);
            }
        }这方法写的不好，我需要改一下*/
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0]<=res.back()[1]){//back是&值，使用前提是不为空
                res.back()[1]=max( res.back()[1],intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        
        return res;
    }
};