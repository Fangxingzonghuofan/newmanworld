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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        vector<vector<int>> ans;
        if(!root) return ans;
        while (!nodeQueue.empty())
        {
            int size=nodeQueue.size();
            vector<int>rownode;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node=nodeQueue.front();
                rownode.push_back(node->val);
                nodeQueue.pop();
                if(node->left) nodeQueue.push(node->left);
                if(node->right) nodeQueue.push(node->right);
            }
            ans.push_back(rownode);
        }
        return ans;
    }
};