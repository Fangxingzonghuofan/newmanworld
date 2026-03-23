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
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
    bool same(vector<vector<int>>& grid,int x,int y,int len){
        int first=grid[x][y];
        for (int i = x; i < x+len; i++)
        {
            for (int j = y; j < y+len; j++)
            {
                if(first!=grid[i][j]) return false;
            }
        }
        return true;
    }
    Node* build(vector<vector<int>>& grid,int x,int y,int len){
        if(same(grid,x,y,len)){
            Node *newnode=new Node(grid[x][y],true);
            return newnode;
        }
        int half=len/2;
        Node* node=new Node(0,false);
        node->topLeft=build(grid,x,y,half);
        node->topRight=build(grid,x,y+half,half);
        node->bottomLeft=build(grid,x+half,y,half);
        node->bottomRight=build(grid,x+half,y+half,half);
        return node;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid,0,0,grid.size());
    }
};//这版已经正确，不过same判断时间复杂度为o(n2)，下面优化到o(1);
class Solution {
    vector<vector<int>> sum; // 前缀和数组

    // 🔹 O(1) 获取子矩阵和
    int getSum(int x, int y, int len) {
        int x2 = x + len;
        int y2 = y + len;
        return sum[x2][y2]
             - sum[x][y2]
             - sum[x2][y]
             + sum[x][y];
    }

    // 🔹 判断当前区域是否全相同（O(1)）
    bool same(int x, int y, int len) {
        int total = getSum(x, y, len);
        // 全0 或 全1
        return total == 0 || total == len * len;
    }

    // 🔹 构建四叉树
    Node* build(vector<vector<int>>& grid, int x, int y, int len) {
        // 如果当前区域全相同 → 直接返回叶子节点
        if (same(x, y, len)) {
            return new Node(grid[x][y], true);
        }

        // 否则划分四块
        int half = len / 2;

        Node* node = new Node(1, false); // 非叶子节点，val无意义

        node->topLeft = build(grid, x, y, half);
        node->topRight = build(grid, x, y + half, half);
        node->bottomLeft = build(grid, x + half, y, half);
        node->bottomRight = build(grid, x + half, y + half, half);

        return node;
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();

        // 🔥 Step 1：构建前缀和（n+1 是为了方便计算）
        sum.assign(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = grid[i - 1][j - 1]
                          + sum[i - 1][j]
                          + sum[i][j - 1]
                          - sum[i - 1][j - 1];
            }
        }

        // 🔥 Step 2：递归构建四叉树
        return build(grid, 0, 0, n);
    }
};