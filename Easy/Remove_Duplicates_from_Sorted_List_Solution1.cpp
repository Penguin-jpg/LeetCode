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
    ListNode* deleteDuplicates(ListNode* head) {
        /*
            我的方法
            複雜度O(length of list)，用Two Pointer的方式找出重複的節點
        */

        /*
            head為NULL或長度為1時，可以直接回傳
        */
        if(!head||!head->next)
        {
            return head;
        }

        //指向上個一樣的節點
        ListNode* previous=head;
        //指向目前的節點
        ListNode* current=head->next;
        
        while(current)
        {
            //如果值一樣，就略過目前節點，讓上次一樣的節點接到目前節點的下一個節點
            if(current->val==previous->val)
            {
                previous->next=current->next;
                //刪除節點
                delete current;
                //重新指派current
                current=previous->next;
            }else
            {
                previous=previous->next;
                current=current->next;  
            }
              
        }     
        return head;
    }
};