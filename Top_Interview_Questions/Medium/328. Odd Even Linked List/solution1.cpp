/**
 * 想法: 透過一個 counter 紀錄目前的奇偶，counter%2==1 是奇數，counter%2==0 是偶
 * 數，把奇數的部分存到另一個 node 後串起來， 再把偶數的部分比照處理，最後將偶數
 * 接到奇數後
 * 時間: O(n), 空間: O(1)
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

class Solution
{
  public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        int counter = 1;
        ListNode *oddDummy = new ListNode(0), *odd = oddDummy;
        ListNode *evenDummy = new ListNode(0), *even = evenDummy;
        ListNode *current = head;
        while (current != nullptr)
        {
            if (counter % 2 == 1)
            {
                odd->next = current;
                odd = odd->next;
            }
            else
            {
                even->next = current;
                even = even->next;
            }
            current = current->next;
            counter++;
        }
        // if the length of list is odd, there will be another node after the
        // last even node. we need to set next to nullptr to prevent cycle
        even->next = nullptr;
        odd->next = evenDummy->next;
        return oddDummy->next;
    }
};