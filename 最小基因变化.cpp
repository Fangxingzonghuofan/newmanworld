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
    bool judge(string a,string b){
        int num=0;
        for (int i = 0; i < 8; i++)
        {
            if (a[i]!=b[i])
            {
                num++;
            }
        }
        return num==1;
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        bank.emplace_back(startGene);
        int size=bank.size();
        int start=-1,end=-1;
        vector<vector<int>>link(size);
        vector<bool>vis(size,false);
        for (int i = 0; i < size; i++)
        {
            if(bank[i]==startGene) start=i;
            if(bank[i]==endGene) end=i;
            for (int j = 0; j <size; j++)
            {
                if(judge(bank[i],bank[j])) link[i].push_back(j);
            }
        }
        if(end==-1) return -1;
        queue<pair<int,int>> geneQue;
        geneQue.emplace(start,0);
        vis[start]=true;
        while(!geneQue.empty())
        {
            auto changing=geneQue.front();
            geneQue.pop();
            for(auto &i:link[changing.first]){
                if (i==end)
                {
                    return changing.second+1;
                }
                if(!vis[i]){
                    vis[i]=1;
                    geneQue.emplace(i,changing.second+1);
                }
            }
        }
        return -1;
    }
};