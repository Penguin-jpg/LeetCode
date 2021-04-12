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
    ListNode* reverseList(ListNode* head) {
        /*
            我的方法
            複雜度O(length of list)，將目前節點的next改接到上一個節點就能完成反轉
        */

        //如果為NULL，就直接回傳head
        if(!head)
        {
            return head;
        }
        
        //分別代表上一個、目前的、下一個節點
        ListNode* previous=NULL;
        ListNode* current=head;
        ListNode* temp=head->next;
        
        //反轉(將next改接到上一個節點)
        while(current->next)
        {
            current->next=previous;
            previous=current;
            current=temp;
            temp=temp->next;
        }
        //迴圈不會做到最後一個，要額外出來做
        current->next=previous;
        //重新指派head
        head=current;
        
        return head;
    }
};