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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*
            自己想法(80%)加參考(20%)的方法
            時間複雜度O(n)、空間複雜度O(1)
            先讓較長的那一個list先走(兩個list的長度差)個節點，再往後比是否有相同節點
        */

        if(headA==NULL||headB==NULL)
        {
            return NULL;
        }
        
        int lenA=getLength(headA);
        int lenB=getLength(headB);
        
        if(lenA-lenB>0)
        {
            int diff=lenA-lenB;
            for(int n=0;n<diff;n++)
            {
                headA=headA->next;
            }
        }else
        {
            int diff=lenB-lenA;
            for(int n=0;n<diff;n++)
            {
                headB=headB->next;
            }
        }
        
        while(headA!=NULL)
        {
            if(headA==headB)
            {
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        
        return NULL;
    }
    
    int getLength(ListNode* head)
    {
        int len=0;
        ListNode* current=head;
        
        while(current!=NULL)
        {
            len++;
            current=current->next;
        }
        
        return len;
    }
};