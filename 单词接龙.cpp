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
        for (int i = 0; i <a.size(); i++)
        {
            if(a[i]!=b[i]) num++;
        }
        return num==1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.emplace_back(beginWord);
        int size=wordList.size();
        vector<vector<int>> linkwords(size);
        vector<bool> vis(size,false);
        int begin=-1,end=-1;
        for(int i=0;i<size;++i){
            if(wordList[i]==beginWord) begin=i;
            if(wordList[i]==endWord) end=i;
            for (int j = i+1; j < size; j++)
            {
                if(judge(wordList[i],wordList[j])){
                    linkwords[i].push_back(j);
                    linkwords[j].push_back(i);
                }
            }
        }
        if(end==-1) return 0;
        queue<pair<int,int>> q;
        q.emplace(begin,1);
        while (!q.empty())
        {
            auto cur=q.front();
            q.pop();
            for (auto &i:linkwords[cur.first])
            {
                if(i==end) return cur.second+1;
                if(!vis[i]){
                    q.emplace(i,cur.second+1);
                    vis[i]=true;
                }
            }
        }
        return 0;
    }
};//和上一题最小基因变化一模一样的思路，但是在这里时间消耗会很大，推荐使用隐式建图法
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> exitWord(wordList.begin(),wordList.end());
        if(!exitWord.count(endWord)) return 0;
        queue<pair<string,int>> q;
        q.emplace(beginWord,1);
        while (!q.empty())
        {
            auto cur=q.front();
            q.pop();
            for (int i = 0; i <beginWord.size(); i++)
            {
                string temp=cur.first;
                for (char j = 'a'; j <='z'; j++)
                {
                    temp[i]=j;
                    if(temp==endWord) return cur.second+1;
                    if(exitWord.count(temp)){
                        q.emplace(temp,cur.second+1);
                        exitWord.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};