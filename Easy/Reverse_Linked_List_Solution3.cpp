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
            參考的方法2
            空間複雜度O(n)、時間複雜度O(1)
            直接操作head，不另外宣告current
        */

        //如果為NULL，就直接回傳head
        if(!head)
        {
            return head;
        }
        
        //分別代表上一個、下一個節點
        ListNode* previous=NULL;
        ListNode* nextNode=NULL;
        
        //反轉(將next改接到上一個節點)
        while(head)
        {
            nextNode=head->next;
            head->next=previous;
            previous=head;
            head=nextNode;
        }
        
        return previous;
    }
};