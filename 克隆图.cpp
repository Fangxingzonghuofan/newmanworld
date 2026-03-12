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
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
public:
    unordered_map<int,bool>visited;
    Node* cloneGraph(Node* node) {
        if (visited.count(node->val))
        {
            return nullptr;
        }
        visited[node->val]=true;
        Node* newnode=new Node(node->val,node->neighbors);
        for(auto &i:node->neighbors){
            cloneGraph(i);
        }  
        return newnode;
    }
};//这一顿乱写也是写错了好吧,下面直接上官方题解
class Solution {
public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        if (visited.count(node))
            return visited[node];

        Node* newnode = new Node(node->val);

        visited[node] = newnode;

        for (auto &i : node->neighbors) {
            newnode->neighbors.push_back(cloneGraph(i));
        }

        return newnode;
    }
};//附赠一套图的DFS模板：
unordered_map<Node*,Node*> visited;

Node* dfs(Node* node){

    if(visited.count(node))
        return visited[node];

    Node* newnode=new Node(node->val);

    visited[node]=newnode;

    for(auto &i:node->neighbors){
        newnode->neighbors.push_back(dfs(i));
    }

    return newnode;
}
