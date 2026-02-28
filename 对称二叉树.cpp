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
    TreeNode* invertTree(TreeNode *root) {
        if (!root)
        {
            return root;
        }
        else swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
    bool isSameTree(TreeNode *p,TreeNode *q){
        bool is1,is2;
        if (!p&&!q)
        {
            return true;
        }
        else if(p==nullptr||q==nullptr||p->val!=q->val){
            return false;
        }
        is1=isSameTree(p->left,q->left);
        is2=isSameTree(p->right,q->right);
        return is1&&is2;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        invertTree(root->right);
        return isSameTree(root->left,root->right);
    }
};//这一题其实就是整合前两题 翻转二叉树 相同的树 ，较为简单,同时还有迭代器的方法，留给以后的我继续学