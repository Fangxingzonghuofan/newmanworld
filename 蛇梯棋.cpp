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
    pair<int,int> idTorc(int id,int n){
        int r=(id-1)/n,c=(id-1)%n;
        if (r%2==1)
        {
            c=n-1-c;
        }
        return {n-1-r,c};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int> vis(n*n+1);
        queue<pair<int,int>>q;//一个是id，一个是到这里经历的步骤
        q.emplace(1,0);
        while (!q.empty())
        {
            auto p=q.front();
            q.pop();
            for (int i = 1; i <=6; i++)
            {
                int nxt=p.first+i;
                if (nxt>n*n)
                {
                    break;
                }
                auto rc=idTorc(nxt,n);
                if(board[rc.first][rc.second]!=-1){
                    nxt=board[rc.first][rc.second];
                }
                if (nxt==n*n)
                {
                    return p.second+1;
                }
                if (!vis[nxt])
                {
                    vis[nxt]=true;
                    q.emplace(nxt,p.second+1);
                }
            }
        }
        return -1;
    }
};//这一题思路不难，但是没写出来（看着题解自己理解过后抄的），把他想象为一个图即可，要注意蛇或梯子的强制到达