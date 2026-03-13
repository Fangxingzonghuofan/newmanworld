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
    bool dfs(int cur,vector<vector<int>>& prerequisites,unordered_set<int>& exitpre){
        if (exitpre.count(cur)) return false;
        exitpre.insert(cur);
        for(auto &i:prerequisites){
            if(i[0]==cur){
                if(!dfs(i[1],prerequisites,exitpre))
                return false;
            }
        }
        exitpre.erase(cur);
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto& i:prerequisites){
            unordered_set<int> exitpre;
            if(!dfs(i[0],prerequisites,exitpre)) {
                return false;
            }
        }
        return true;
    }
};//自己的思路，但是写着一直有问题，最后用ai改了改才写出来，还超过了时间限制
//都说了多少遍了！！！要先建图！！！
class Solution {
public:
    vector<vector<int>>graph;
    vector<int> state;
    bool dfs(int node){
        if(state[node]==1) return false;
        if(state[node]==2) return true;
        state[node]=1;
        for(int next:graph[node]){
            if(!dfs(next)) return false;
        }
        state[node]=2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        state.reserve(numCourses);
        for(auto &p:prerequisites){
            graph[p[0]].push_back(p[1]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if(!dfs(i)) return false;
        }
        return true;
    }
};