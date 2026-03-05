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
    vector<int> res;
    int idx=0;
    void dfs(TreeNode* root,int depth){
        if(!root) return;
        depth++;
        if(depth>idx) {
            res.push_back(root->val);
            idx++;
        }
        dfs(root->right,depth);
        dfs(root->left,depth);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        return res;
    }
};