/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> nums;
    vector<int> preorder(Node* root) {
        /*
            我的方法1
            時間複雜度O(n)、空間複雜度O(n)
            遞迴
        */

        traversal(root);
        return nums;
    }
    
    void traversal(Node* root)
    {
        if(root==NULL)
        {
            return;
        }
        
        nums.push_back(root->val);
        for(int n=0;n<root->children.size();n++)
        {
            preorder(root->children[n]);
        }
    }
};