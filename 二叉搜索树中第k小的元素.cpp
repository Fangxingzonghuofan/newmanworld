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
    int index=0;
    int aimNode;
    void inorder(TreeNode* root,int k){
        if(!root) return;
        inorder(root->left,k);
        index++;
        if (index==k)
        {
          aimNode=root->val;
        }
        inorder(root->right,k);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return aimNode;
    }
};