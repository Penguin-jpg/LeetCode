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
    bool isPalindrome(ListNode* head) {
        /*
            參考的方法
            時間複雜度O(n)、空間複雜度O(1)
            快慢指標
        */

        ListNode* fast=head;
        ListNode* slow=head;
        
        //利用快慢指標，當fast走完時，slow剛好到一半
        while(fast!=NULL&&fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        
        if(fast!=NULL) //fast==NULL時是偶數，會在正確的位置，但奇數需要再往下一格，才會在正確的位置
        {
            slow=slow->next;
        }
        
        slow=reverse(slow); //反轉右半邊的list，才會和左半邊順序一樣
        fast=head; //將fast退回原點
        
        //比較左右半邊的數是否相同
        while(slow!=NULL)
        {
            if(fast->val!=slow->val)
            {
                return false;
            }
            
            fast=fast->next;
            slow=slow->next;
        }
        
        return true;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* previous=NULL;
        ListNode* nextNode=NULL;
        
        while(head!=NULL)
        {
            nextNode=head->next;
            head->next=previous;
            previous=head;
            head=nextNode;
        }
        
        return previous;
    }
};