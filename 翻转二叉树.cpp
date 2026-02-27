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
    TreeNode* invertTree(TreeNode* root) {
        if (root==nullptr)//(!root)
        {
            return root;
        }
        else
        {
            TreeNode *tmp;
            tmp=root->left;
            root->left=root->right;
            root->right=tmp;
        }//这一段可以直接写swap函数swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};