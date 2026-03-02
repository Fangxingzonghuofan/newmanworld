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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
        {
            return false;
        }
        bool yes1,yes2;
        if (root->left==nullptr&&root->right==nullptr)
        {
            if(root->val==targetSum) return true;
            else return false;
        }
        yes1=hasPathSum(root->left,targetSum-root->val);
        yes2=hasPathSum(root->right,targetSum-root->val);
        return yes1||yes2;
    }
};