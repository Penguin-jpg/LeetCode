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
            我的方法1
            時間複雜度O(n)、空間複雜度O(n)
            利用stack檢查是否是回文
        */

        int len=getLen(head);
        stack<int> nums;
        ListNode* current=head;
        
        for(int i=0;i<len/2;i++) //先放一半
        {
            nums.push(current->val);
            current=current->next;
        }
        
        if(len%2==0) //偶數可以直接檢查另一半
        {
            for(int i=len/2;i<len;i++)
            {
                if(nums.top()!=current->val)
                {
                    return false;
                }
                nums.pop();
                current=current->next;
            }
        }else //奇數需要跳過中間的節點再檢查
        {
            current=current->next; //跳過中間的節點
            for(int i=len/2+1;i<len;i++)
            {
                if(nums.top()!=current->val)
                {
                    return false;
                }
                nums.pop();
                current=current->next;
            }
        }
        
        return true;
    }
    
    int getLen(ListNode* head)
    {
        ListNode* current=head;
        int len=0;
        
        while(current!=NULL)
        {
            len++;
            current=current->next;
        }
        
        return len;
    }
};