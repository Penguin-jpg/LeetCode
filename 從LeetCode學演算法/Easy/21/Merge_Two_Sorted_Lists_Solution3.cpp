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
            參考的方法2
            使用Dummy node，操作指向dummy的指標，將l1和l2比較後接上，最後回傳再透過dummy->next取得答案
        */
        //其中一個為NULL，就回傳另一個list
        if(!l1)
        {
            return l2;
        }else if(!l2)
        {
            return l1;
        }
        
        //Dummy Node
        ListNode *dummy=new ListNode();
        ListNode *current=dummy;
        
        //比較大小後，將較小的接在後面
        while(l1&&l2)
        {
            if(l1->val<=l2->val)
            {
                current->next=l1;
                l1=l1->next;
            }else
            {
                current->next=l2;
                l2=l2->next;
            }
            current=current->next;
        }
        
        //將剩下的list街上
        if(l1)
        {
            current->next=l1;
        }else
        {
            current->next=l2;
        }
        
        //從開頭的下一個開始才是所求的list
        return dummy->next;
    }
};