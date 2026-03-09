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
int minVal=INT_MAX;
TreeNode*pre=nullptr;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if (pre)
        {
            minVal=min(minVal,root->val-pre->val);
        }
        pre=root;//虽然是全局变量，但是pre的值一直往前遍历不会回退，故可以使用
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minVal;
    }
};