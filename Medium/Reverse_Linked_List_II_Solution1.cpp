/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        /*
            參考的方法
            複雜度O(n)，利用stack後進先出的特性達成反轉的目標
        */

        if(left==right)
        {
            return head;
        }
        
        stack<ListNode*> nodes;
        //第left個節點的上一個節點
        ListNode* leftNode=NULL;
        ListNode* current=head;
        
        if(left!=1)
        {
            //找出第left個節點的上一個節點
            for(int n=1;n<left-1;n++)
            {
                current=current->next;
            }
            leftNode=current;
            //往下移到第left個節點
            current=current->next;
        }
        
        //將要反轉的節點加入stack
        for(int n=left;n<=right;n++)
        {
            nodes.push(current);
            current=current->next;
        }
        
        ListNode* node=nodes.top();
        nodes.pop();
        
        //如果left為第一個節點，需要特殊處理
        if(left==1)
        {
            head=node;
        }else //從原本left左邊的節點往下接
        {
            leftNode->next=node;
        }
        
        //將節點反轉接上
        while(!nodes.empty())
        {
            node->next=nodes.top();
            nodes.pop();
            node=node->next;
        }
        //接上第right個右邊的節點
        node->next=current;
        
        return head;
    }
};