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
    vector<string> res;
    void backtrack(int n,int leftnum,int gapnum,string &path){
        if (leftnum==n&&gapnum==0)
        {
            res.push_back(path);
            return;
        }
        if(leftnum<=n)
        {
            path.push_back('(');
            leftnum++;
            gapnum++;
            backtrack(n,leftnum,gapnum,path);
            path.pop_back();
            leftnum--;
            gapnum--;
            if (gapnum>0)
            {
                path.push_back(')');
                gapnum--;
                backtrack(n,leftnum,gapnum,path);
                path.pop_back();
                gapnum++;
            }
        } 
    }
public:
    vector<string> generateParenthesis(int n) {
        string path;
        backtrack(n,0,0,path);
        return res;
    }
};
//时间复杂度对了，但是无法击败100%，下面进行修改使其规范化
class Solution {
    vector<string> res;
    void backtrack(int n,int leftnum,int gapnum,string &path){
        if (leftnum==n&&gapnum==0)
        {
            res.push_back(path);
            return;
        }
        if(leftnum<n)
        {
            path.push_back('(');
            backtrack(n,leftnum+1,gapnum+1,path);
            path.pop_back();
        }
            if (gapnum>0)
            {
                path.push_back(')');
                backtrack(n,leftnum,gapnum-1,path);
                path.pop_back();
            }
    }
public:
    vector<string> generateParenthesis(int n){
        string path;
        backtrack(n,0,0,path);
        return res;
    }
};
