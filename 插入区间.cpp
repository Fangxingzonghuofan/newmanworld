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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i=0;
        while(i <intervals.size()&&newInterval[0]>=intervals[i][0])
        {
            i++;
        }
        for (int j= 0; j < i; j++)
        {
            res.emplace_back(intervals[j]);
        }
        if (i==0||newInterval[0]>res.back()[1])
        {
            res.emplace_back(newInterval);
        }
        else if (newInterval[0]<=res.back()[1]&&newInterval[1]>res.back()[1])
        {
            res.back()[1]=newInterval[1];
        }
        for (int j = i; j < intervals.size(); j++)
        {
        if (intervals[j][0]<=res.back()[1]&&intervals[j][1]>res.back()[1])
        {
            res.back()[1]=intervals[j][1];
        }
        else if (intervals[j][0]>res.back()[1])
        {
            res.emplace_back(intervals[j]);
        }
        }
        return res;
    }
};