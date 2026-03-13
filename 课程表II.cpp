#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;//这一题要用上一题课程表的思路，上一题我用的dfs，这一次尝试使用bfs加拓扑解题
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        vector<int> ans;
        for(auto& p:prerequisites){
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        stack<int> zeroNode;
        for (int i = 0; i <numCourses; i++)
        {
            if (indegree[i]==0)
            {
                zeroNode.push(i);
            }
        }
        int count=0;
        while (!zeroNode.empty())
        {
            int cur=zeroNode.top();
            zeroNode.pop();
            count++;
            ans.push_back(cur);
            for(auto &i:graph[cur]){
                indegree[i]--;
                if (indegree[i]==0)
                {
                    zeroNode.push(i);
                }
            }
        }
        if(count!=numCourses){
            vector<int> nullans;
            return nullans;
        }
        return ans;
    }
};