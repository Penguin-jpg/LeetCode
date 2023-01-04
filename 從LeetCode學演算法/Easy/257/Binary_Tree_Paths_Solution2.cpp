/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        /*
            參考的方法
            時間複雜度O(n)(n為總結點數)、空間複雜度O(mlog(n))(m為路徑數，n為總結點數)
            將所有走過的記錄下來，當遇到leaf node時，將走過的路徑存到陣列，並移除最後一個走過的節點
        */

        vector<string> results;
        vector<int> nodes;
        findPath(root,nodes,results);
        return results;
    }
    
    void findPath(TreeNode* root,vector<int>& nodes,vector<string>& results)
    {
        nodes.push_back(root->val);
        
        if(root->left!=NULL)
        {
            findPath(root->left,nodes,results);
        }
        if(root->right!=NULL)
        {
            findPath(root->right,nodes,results);
        }
        
        if(root->left==NULL&&root->right==NULL)
        {
            string path="";
            for(int n=0;n<nodes.size();n++)
            {
                path+=to_string(nodes[n]);
                if(n!=nodes.size()-1)
                {
                    path+="->";
                }
            }
            results.push_back(path);
        }
        nodes.pop_back();
    }
};