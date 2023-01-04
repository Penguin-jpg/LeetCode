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
            參考的方法
            時間複雜度O(n)、空間複雜度O(1)
            利用dummy node，可以不用管head的位置
        */

        ListNode* dummy=new ListNode(0,head);
        ListNode* current=dummy;
        
        while(current->next!=NULL)
        {
            if(current->next->val==val)
            {
                current->next=current->next->next;
            }else
            {
                current=current->next;
            }
        }
        
        return dummy->next;
    }
};