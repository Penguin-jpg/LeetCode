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
    ListNode* removeElements(ListNode* head, int val) {
        /*
            我的方法
            時間複雜度O(n)、空間複雜度O(1)
        */

        if(head==NULL)
        {
            return head;
        }
        
        ListNode* previous=NULL;
        ListNode* current=head;
        
        while(current!=NULL)
        {
            if(current->val==val)
            {    
                if(previous!=NULL)
                {
                    previous->next=current->next;;
                }else //要刪除的是head
                {
                    head=current->next; //更新head的位置
                }
                current=current->next;
            }else
            {
                previous=current;
                current=current->next;
            }
        }
        
        return head;
    }
};