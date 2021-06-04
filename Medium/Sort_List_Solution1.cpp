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
    ListNode* sortList(ListNode* head) {
        /*
            我的方法
            時間複雜度O(nlog(n))、空間複雜度O(n)
            先將節點的值存起來排序，再重新把值傳回去
        */

        if(head==NULL)
        {
            return head;
        }
        
        vector<int> nums;
        ListNode* current=head;
        int index=0;
        
        while(current!=NULL)
        {
            nums.push_back(current->val);
            current=current->next;
        }
        
        sort(nums.begin(),nums.end());
        current=head;
        
        while(current!=NULL)
        {
            current->val=nums[index];
            current=current->next;
            index++;
        }
        
        return head;
    }
};