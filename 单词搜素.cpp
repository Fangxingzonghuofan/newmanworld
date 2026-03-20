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
    vector<vector<bool>> vis;
    bool exit=false;
    void backtrack(vector<vector<char>>& board, string &word,int r,int c,int index,vector<vector<bool>> &vis){
        if (index==word.size()-1)
        {
            exit=true;
            return;
        }
        if(exit) return;
        if (r+1<board.size()&&vis[r+1][c]==false&&board[r+1][c]==word[index+1])
        {
            vis[r+1][c]=true;
            backtrack(board,word,r+1,c,index+1,vis);
            vis[r+1][c]=false;
        }
        if (c+1<board[0].size()&&vis[r][c+1]==false&&board[r][c+1]==word[index+1])
        {
            vis[r][c+1]=true;
            backtrack(board,word,r,c+1,index+1,vis);
            vis[r][c+1]=false;
        }
        if(r-1>=0&&vis[r-1][c]==false&&board[r-1][c]==word[index+1])
        {
            vis[r-1][c]=true;
            backtrack(board,word,r-1,c,index+1,vis);
            vis[r-1][c]=false;
        }
        if(c-1>=0&&vis[r][c-1]==false&&board[r][c-1]==word[index+1])
        {
            vis[r][c-1]=true;
            backtrack(board,word,r,c-1,index+1,vis);
            vis[r][c-1]=false;
        }
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vis=vector<vector<bool>>(board.size(),vector<bool>(board[0].size(),false));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j <board[0].size(); j++)
            {
                if(board[i][j]==word[0]){
                    vis[i][j]=true;
                    backtrack(board,word,i,j,0,vis);
                    vis[i][j]=false;
                }
                if(exit) return true;
            }
        }
        return exit;
    }
};//自己摸索着写出来了，但是并不是最规范的写法，时间和空间开销还可以再小一点，下面给出更优化的写法
//这一版更优在于删去了其实不需要传递的形参vis，写法上更加明朗，时间和空间复杂度相差不多
class Solution {
    vector<vector<bool>> vis;
    bool found = false;

    void backtrack(vector<vector<char>>& board, string &word, int r, int c, int index) {
        if (index == word.size()) {
            found = true;
            return;
        }

        if (found) return;

        int m = board.size(), n = board[0].size();

        // 越界 or 不匹配 or 已访问
        if (r < 0 || c < 0 || r >= m || c >= n ||
            vis[r][c] || board[r][c] != word[index]) {
            return;
        }

        vis[r][c] = true;

        backtrack(board, word, r + 1, c, index + 1);
        backtrack(board, word, r - 1, c, index + 1);
        backtrack(board, word, r, c + 1, index + 1);
        backtrack(board, word, r, c - 1, index + 1);

        vis[r][c] = false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vis = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                backtrack(board, word, i, j, 0);
                if (found) return true;
            }
        }
        return false;
    }
};
//可以优化空间复杂度：
/*
char temp = board[r][c];
board[r][c] = '#';

// dfs

board[r][c] = temp;
*/