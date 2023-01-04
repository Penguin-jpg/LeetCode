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
            我的方法
            將l1和l2的val都放進一個陣列後，將陣列排序，並將val依序放到一個新的list
        */
        //其中一個為NULL，就回傳另一個list
        if(l1==NULL)
        {
            return l2;
        }else if(l2==NULL)
        {
            return l1;
        }
        
        //l1,l2長度和新list的開頭
        ListNode *head=new ListNode();
        int len1=length(l1);
        int len2=length(l2);
        int nums[100]={0};
        
        //將l1,l2的val存進陣列
        for(int n=0;n<len1;n++)
        {
            nums[n]=l1->val;
            l1=l1->next;
        }
        for(int n=len1;n<len1+len2;n++)
        {
            nums[n]=l2->val;
            l2=l2->next;
        }
        
        //排序
        sort(nums,nums+len1+len2);
        
        //放入新的list
        for(int n=0;n<len1+len2;n++)
        {
            createNode(nums[n],head);
        }
        
        return head->next;
    }
    
    //計算list長度
    int length(ListNode *list)
    {
        if(list==NULL)
        {   
            return 0;
        }
        
        int len=0;
        ListNode *current=list;
        while(current!=NULL)
        {
            len++;
            current=current->next;
        }
        return len;
    }
    
    //建立新節點
    void createNode(int val,ListNode *head)
    {
        ListNode *newNode=new ListNode(val);
        
        ListNode *current=head;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=newNode;
    }
};