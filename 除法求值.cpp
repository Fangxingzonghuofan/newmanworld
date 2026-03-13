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
    unordered_map<string,bool> exit;
    double dfs(vector<vector<string>>& equations,vector<double>& values,string head,string tail,double ans){
        if(!exit.count(head)||!exit.count(tail)) return -1.0;
        if(head==tail) return 1.0;
        for(int i=0;i<equations.size();i++){
            if (equations[i][0]==head)
            {
                if(equations[i][1]==tail) return ans*values[i];
                return ans*dfs(equations,values,equations[i][1],tail,values[i]);
            }
            if (equations[i][0]==tail)
            {
                if(equations[i][1]==head) return ans*1/values[i];
                return ans*dfs(equations,values,head,equations[i][1],1/values[i]);
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        for(auto &i:equations){
            exit[i[1]]=true;
            exit[i[0]]=true;
        }
        for(auto &i:queries){
            double res=dfs(equations,values,i[0],i[1],1);
            res=res<0?-1:res;

            ans.push_back(res);
        }
        return ans;
    }
};//
class Solution {
public:
    unordered_map<string,bool> exit;
    double dfs(vector<vector<string>>& equations,vector<double>& values,string head,string tail,double ans){
        if(!exit.count(head)||!exit.count(tail)) return -1.0;
        if(head==tail) return 1.0;
        for(int i=0;i<equations.size();i++){
            if (equations[i][0]==head)
            {
                if(equations[i][1]==tail) return ans*values[i];
                return ans*dfs(equations,values,equations[i][1],tail,values[i]);
            }
            if (equations[i][0]==tail||equations[i][1]==head)
            {
                if(equations[i][0]==tail&&equations[i][1]==head) return ans*1/values[i];
                if(equations[i][1]==head)return ans*dfs(equations,values,equations[i][0],tail,1/values[i]);
                if(equations[i][0]==tail)return ans*dfs(equations,values,head,equations[i][1],1/values[i]);
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        for(auto &i:equations){
            exit[i[1]]=true;
            exit[i[0]]=true;
        }
        for(auto &i:queries){
            double res=dfs(equations,values,i[0],i[1],1);
            res=res<0?-1:res;

            ans.push_back(res);
        }
        return ans;
    }
};//以上都是我写了好几个小时的屎山代码，思路大体是对的，但是主要问题存在于没有提前建图
//下面是标准版答案
class Solution {
public:
unordered_map<string,vector<pair<string,double>>> graph;
        double dfs(string cur,string target,unordered_set<string> & visited){
            if(cur==target) return 1.0;
            visited.insert(cur);
            for (auto& i:graph[cur])
            {
                string next=i.first;
                if (visited.count(next)) continue;
                double val=i.second;
                double res=dfs(next,target,visited);
                if(res!=-1.0) return res*val;
            }
            return -1.0;
        }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i <equations.size(); i++)
        {
            string a=equations[i][0];
            string b=equations[i][1];
            double v=values[i];
            graph[a].push_back({b,v});
            graph[b].push_back({a,1.0/v});
        }
        vector<double> ans;
        for(auto &q:queries){
            string a=q[0];
            string b=q[1];
            if(!graph.count(a)||!graph.count(b)){
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string> visitied;
            ans.push_back(dfs(a,b,visitied));
        }
        return ans;
    }
};
