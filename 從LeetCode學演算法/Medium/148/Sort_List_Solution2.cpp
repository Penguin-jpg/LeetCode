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
    ListNode* sortList(ListNode* head) {
        /*
            參考的方法
            時間複雜度O(nlog(n))、空間複雜度O(log(n))
            merge sort
        */

        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL; //紀錄中點的前一個節點
        
        //找中點
        while(fast!=NULL&&fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL; //斷開原本的連結
        
        ListNode* n1=sortList(head); //從head到prev繼續切
        ListNode* n2=sortList(slow); //從slow到尾端繼續切
        
        return merge(n1,n2);
    }
    
    //合併
    ListNode* merge(ListNode* n1, ListNode* n2)
    {
        ListNode* dummy=new ListNode(0);
        ListNode* current=dummy;
        
        while(n1!=NULL&&n2!=NULL)
        {
            if(n1->val<n2->val)
            {
                current->next=n1;
                n1=n1->next;
            }else
            {
                current->next=n2;
                n2=n2->next;
            }
            current=current->next;
        }
        
        if(n1!=NULL)
        {
           current->next=n1;
        }else if(n2!=NULL)
        {
            current->next=n2;
        }
        
        return dummy->next;
    }
};