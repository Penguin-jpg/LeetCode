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
            參考的方法3
            時間複雜度O(n)、空間複雜度O(n)
            用遞迴來做(概念複雜，不建議使用)
        */

        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        
        ListNode* node=reverseList(head->next); //先找到最後一個節點
        head->next->next=head; //每次都將下個節點的next指向自己
        head->next=NULL; //斷開自己原本的連結
        
        return node;
    }
};