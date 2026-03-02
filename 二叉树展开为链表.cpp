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
    TreeNode *tail;
    void flatten(TreeNode* root) {
        if (!root)
        {
            return;
        }
        tail=root;
        while (tail->left)
        {
            tail=tail->left;
        }
        makeflatten(root);
        return;
    }
    void makeflatten(TreeNode* root) {
        if (!root)
        {
            return;
        }
        if (root->left)
        {
            if (root->right)
            {
                tail->right=root->right;
            }
            root->right=root->left;
            root->left=nullptr;
            tail=root->right;
            while (tail->right)
            {
                tail=tail->right;
            }
        }
        makeflatten(root->left);
        makeflatten(root->right);
        return;
    }
};//以上是我自己写的，直接超时了，下面是gpt给我的用我的思路写的标准答案，好了我宣布ai比我厉害一万倍
class Solution {
public:
    void flatten(TreeNode* root) {
        makeflatten(root);
        return;
    }
    TreeNode* makeflatten(TreeNode* root) {
        if (!root)
        {
            return nullptr;
        }
        TreeNode *lefttail=makeflatten(root->left);
        TreeNode *righttail=makeflatten(root->right);
        if (lefttail)
        {
            lefttail->right=root->right;
            root->right=root->left;
            root->left=nullptr;
        }
        if (righttail)
        {
            return righttail;
        }
        if (lefttail)
        {
            return lefttail;
        } 
        return root;
    }
};