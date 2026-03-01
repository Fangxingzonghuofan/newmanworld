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
unordered_map<int,int> index;
    TreeNode* mybuild(vector<int>& inorder, vector<int>& postorder,int inbegin,int inend,int postbegin,int postend){
        if (inbegin>inend)
        {
            return nullptr;
        }
        int rootindex=index[postorder[postend]];
        TreeNode *root=new TreeNode(postorder[postend]);
        int leftlen=rootindex-inbegin;
        root->left=mybuild(inorder,postorder,inbegin,rootindex-1,postbegin,postbegin+leftlen-1);
        root->right=mybuild(inorder,postorder,rootindex+1,inend,postbegin+leftlen,postend-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i <inorder.size() ; i++)
        {
            index[inorder[i]]=i;
        }
        return mybuild(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};