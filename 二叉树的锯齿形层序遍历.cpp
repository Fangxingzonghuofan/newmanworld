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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        vector<vector<int>> ans;
        if(!root) return ans;
        bool flag=true;
        while (!nodeQueue.empty())
        {
            int size=nodeQueue.size();
            deque<int>rownode;//使用双端队列
            for (int i = 0; i < size; i++)
            {
                TreeNode *node=nodeQueue.front();
                if(flag) rownode.push_back(node->val);
                else rownode.push_front(node->val);
                nodeQueue.pop();
                if(node->left) nodeQueue.push(node->left);
                if(node->right) nodeQueue.push(node->right);
            }
            ans.emplace_back(vector<int>{rownode.begin(),rownode.end()});
            flag=!flag;
        }
        return ans;
    }
};