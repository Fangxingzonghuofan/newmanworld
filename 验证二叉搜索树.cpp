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
    bool yess=true;
    TreeNode *pre;
    void checkTree(TreeNode*root){
        if(!root) return;
        checkTree(root->left);
        if (pre)
        {
            if (pre->val>=root->val)
            {
                yess=false;
            }
        }
        pre=root;
        checkTree(root->right);
    }
    bool isValidBST(TreeNode* root) {
        checkTree(root);
        return yess;
    }
};