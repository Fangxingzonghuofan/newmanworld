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
    int maxDepth(TreeNode* root) {
        int lchildh,rchildh;
        if (root==nullptr)
        {
            return 0;
        }
        else{
            lchildh=maxDepth(root->left);
            rchildh=maxDepth(root->right);
        }
        return lchildh>rchildh?(lchildh+1):(rchildh+1);
    }
};