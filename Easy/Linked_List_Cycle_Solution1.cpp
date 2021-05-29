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
    bool hasCycle(ListNode *head) {
        /*
            我的方法(大部分人都是這樣解)
            時間複雜度O(n)、空間複雜度O(1)
            利用快慢指標找出有沒有環
        */

        if(head==NULL||head->next==NULL)
        {
            return false;
        }
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                return true;
            }
        }
        
        return false;
    }
};