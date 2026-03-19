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
    int total=0;
    unordered_set<int> col;
    unordered_set<int> diag1;
    unordered_set<int> diag2;
    void backtrack(int n,int index,int startRow){
        if (index==n+1)
        {
            total++;
            return;
        }
        for (int r = startRow; r <n ; r++)
        {
            for (int c = 0; c <n; c++)
            {
                if(!col.count(c)&&!diag1.count(r-c)&&!diag2.count(r+c))
                {
                    col.insert(c);
                    diag1.insert(r-c);
                    diag2.insert(r+c);
                    backtrack(n,index+1,r+1);
                    col.erase(c);
                    diag1.erase(r-c);
                    diag2.erase(r+c);
                }
            }
        }
    }
public:
    int totalNQueens(int n) {
        backtrack(n,1,0);
        return total;
    }
};//在ai的提示下写出来了一段屎山代码(本质上多写了一段row循环)，时间和空间开销都很大,下面是更改后的算法
class Solution {
    int total=0;
    vector<bool> col;
    vector<bool> diag1;
    vector<bool> diag2;
    void backtrack(int n,int startRow){
        if (startRow==n)
        {
            total++;
            return;
        }
            for (int c = 0; c <n; c++)
            {
                if(!col[c]&&!diag1[startRow-c+n]&&!diag2[startRow+c])
                {
                    col[c]=true;
                    diag1[startRow-c+n]=true;
                    diag2[startRow+c]=true;
                    backtrack(n,startRow+1);
                    col[c]=false;
                    diag1[startRow-c+n]=false;
                    diag2[startRow+c]=false;
                }
            }
    }
public:
    int totalNQueens(int n) {
        col.resize(n,false);
        diag1.resize(2*n,false);
        diag2.resize(2*n,false);
        backtrack(n,0);
        return total;
    }
};
//将unorder_set改为了vector<bool>，减小时间和空间开销
