/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*
            我的方法1
            時間複雜度O(n*m)(n:headA總結點數、m:headB總結點數)、空間複雜度O(1)
            選定一個list當作比較對象，另一個list從頭開始找有沒有相同的節點
        */

        if(headA==NULL||headB==NULL)
        {
            return NULL;
        }
        
        ListNode* current=headA;
        
        while(headB!=NULL)
        {
            while(current!=NULL)
            {
                if(current==headB)
                {
                    return current;
                }
                current=current->next;
            }
            current=headA;
            headB=headB->next;
        }
        
        return NULL;
    }
};