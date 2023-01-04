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
            我的方法2
            時間複雜度O(n)、空間複雜度O(n)
            利用字串紀錄出現過的數字，再檢查字串是否是回文
        */

        string str="";
        ListNode* current=head;
        
        while(current!=NULL)
        {
            str+=current->val+'0';
            current=current->next;
        }
        
        for(int i=0;i<str.length();i++)
        {
            if(str[i]!=str[str.length()-i-1])
            {
                return false;
            }
        }
        
        return true;
    }
};