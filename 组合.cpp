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
    vector<vector<int>> res;
    void backtrack(int n,int begin,int index,int k,vector<int>ans){
        if (index==k+1)
        {
            res.push_back(ans);
            return;
        }
        for (int i = begin; i <n+1; i++)
        {
            ans.push_back(i);
            backtrack(n,i+1,index+1,k,ans);
            ans.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans;
        backtrack(n,1,1,k,ans);
        return res;
    }
};//以上是我写的屎山代码，要改动的地方很多，下面是我修改后的
class Solution {
    vector<vector<int>> res;
    void backtrack(int n,int begin,int k,vector<int>&ans){//这里加上&改为引用，效率更高
        if (ans.size()==k)//index没必要，可以使用ans.size()代替
        {
            res.push_back(ans);
            return;
        }
        for (int i = begin; i <= n - (k - ans.size()) + 1; i++)//这里剪枝，加快速率，公式来源:n - i + 1 (剩余元素个数)>= k - ans.size()(还需要的元素个数)
        {
            ans.push_back(i);
            backtrack(n,i+1,k,ans);
            ans.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans;
        backtrack(n,1,k,ans);
        return res;
    }
};