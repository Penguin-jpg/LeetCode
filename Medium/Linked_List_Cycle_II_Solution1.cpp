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
    ListNode *detectCycle(ListNode *head) {
        /*
            參考的方法
            時間複雜度O(n^2)、空間複雜度O(1)
            先用快慢指標確定是不是環，如果是環，就將其中一個指標退回開頭，
            並且與另一個指標一次走一步，再次相遇點就是環的進入點

            證明:
            https://medium.com/@orionssl/%E6%8E%A2%E7%B4%A2-floyd-cycle-detection-algorithm-934cdd05beb9
        */

        if(head==NULL||head->next==NULL)
        {
            return NULL;
        }
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                slow=head;
                while(slow!=fast)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        
        return NULL;
    }
};