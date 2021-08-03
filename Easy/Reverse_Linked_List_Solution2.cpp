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
            參考的方法1
            時間複雜度O(n)、空間複雜度O(1)
            方法1的改良版，在進入迴圈時直接做temp=current->next，
            並將條件改成current!=NULL，可以不用額外將最後一次額外做，
            最後直接回傳previous，不用重新指派head
        */

        //如果為NULL，就直接回傳head
        if(!head)
        {
            return head;
        }
        
        //分別代表上一個、目前的、下一個節點
        ListNode* previous=NULL;
        ListNode* current=head;
        ListNode* temp=NULL;
        
        //反轉(將next改接到上一個節點)
        while(current)
        {
            temp=current->next;
            current->next=previous;
            previous=current;
            current=temp;
        }
        
        return previous;
    }
};