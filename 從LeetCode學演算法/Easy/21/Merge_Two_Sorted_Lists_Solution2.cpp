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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        /*
            參考的做法1
            使用Iterative方法，先取出較小的list作為開頭，再透過此list的下個節點與另一個list做比較，以達到排序的效果
        */
        //取非NULL的list
        ListNode *head=l1!=NULL?l1:l2;
        
        //其中之一為NULL，就回傳非NULL的
        if(l1==NULL||l2==NULL)
        {
            return head;
        }
        
        //另一個list
        ListNode *other=l2;
        
        //找出先後順序
        if(head->val>other->val)
        {
            head=other;
            other=l1;
        }
        
        //排序
        ListNode *current=head;
        while(current!=NULL&&other!=NULL)
        {
            //current仍然比other小
            if(current->next!=NULL&&current->next->val<other->val)
            {
                current=current->next;
            }else//current->next的val比other大
            {
                ListNode *temp=current->next;
                current->next=other;
                current=other;
                other=temp;
            }
        }
        return head;
    }
};
