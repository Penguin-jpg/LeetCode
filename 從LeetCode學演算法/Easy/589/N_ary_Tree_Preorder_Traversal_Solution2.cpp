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
            我的方法2
            時間複雜度O(n)、空間複雜度O(n)
            Iterative，利用stack的後進先出的特性，將要先輸出的最後放
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
        
        stack<Node*> nodes;
        nodes.push(root);
        
        while(!nodes.empty())
        {
            Node* current=nodes.top();
            nodes.pop();
            nums.push_back(current->val);
            
            for(int n=current->children.size()-1;n>=0;n--)
            {
                if(current->children[n]!=NULL)
                {
                    nodes.push(current->children[n]);
                }
            }
        }
    }
};