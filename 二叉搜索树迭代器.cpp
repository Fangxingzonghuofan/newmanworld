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
class BSTIterator {
public:
int idx;
vector<int> res;
    void inorder(TreeNode *root,vector<int> &res){
        if (!root)
        {
            return;
        }
        inorder(root->left,res);
        res.emplace_back(root->val);
        inorder(root->right,res);
        return;
    }
    BSTIterator(TreeNode* root):idx(0){
        inorder(root,res);
        return;
    }
    int next() {
        return res[idx++];
    }
    
    bool hasNext() {
        if (idx<res.size())
        {
            return true;
        }
        return false;
    }
};