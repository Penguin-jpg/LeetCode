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
            參考的方法4
            時間複雜度O(n)、空間複雜度O(n)
            概念上較接近迴圈版的遞迴版
        */

        return reverse(NULL, head);
    }
    
    ListNode* reverse(ListNode* previous,ListNode* current)
    {
        if(current==NULL)
        {
            return previous;
        }
        
        ListNode* nextNode=current->next;
        current->next=previous;
        
        return reverse(current, nextNode);
    }
};