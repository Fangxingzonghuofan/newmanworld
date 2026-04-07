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
    bool wordBreak(string s, vector<string>& wordDict) {
        //自己是没有思路的，但是被ai点了一下就知道该怎么做了
        unordered_set<string> dict;
        for(auto &i:wordDict){
            dict.insert(i);
        }//建议改为unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int size=s.size();
        vector<bool> dp(size+1,false);
        dp[0]=true;
        for (int i = 1; i < size+1; i++)
        {
            for (int j = 0; j <i; j++)
            {
                if(dp[j]){
                    string A=string(s.begin()+j,s.begin()+i);//string A = s.substr(j, i - j);这里这样写更方便
                    if(dict.count(A)) {
                        dp[i]=true;
                        break;//这里加上break更好
                    }
                } 
            }
        }
        return dp[size];
    }
};
//思路和官方题解一样，但是无法做到100%时间击败，下面给出“背包”思路

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        int m=wordDict.size();
        vector<bool> A(n+1,false);
        A[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                if(wordDict[j].size()>i)continue;
                string st=s.substr(i-wordDict[j].size(),wordDict[j].size());
                if(A[i-wordDict[j].size()]==1&&wordDict[j]==st)A[i]=true;
            }            
        }
        return A[n];
    }
};