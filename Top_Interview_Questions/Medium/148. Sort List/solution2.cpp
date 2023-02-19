#include <algorithm>
#include <vector>
using namespace std;

/**
 * 參考解答: 用快慢指標和 merge sort 來解，雖然 merge sort 對陣列來說會需要額外
 * 的 O(n) 空間，但對 linked list 來說，可以透過檢查 next 是否為 NULL 來避免這種
 * edge case，所以只需要 O(1) 的空間，快慢指標只是用來幫我們走到 list 的中點
 * 時間: O(nlogn), 空間: O(1)
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
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr) // no node or only one node left
        {
            return head;
        }
        ListNode *slow = head, *fast = head, *temp = nullptr;
        while (fast != nullptr && fast->next != nullptr)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // now we have to sub lists [head, temp], [slow, tail]
        // to seperate two sub lists, we can next of the last node to nullptr
        temp->next = nullptr;
        ListNode *list1 = sortList(head); // keep divide
        ListNode *list2 = sortList(slow);
        return merge(list1, list2);
    }

    ListNode *merge(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                current->next = list1;
                list1 = list1->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        while (list1 != nullptr)
        {
            current->next = list1;
            list1 = list1->next;
            current = current->next;
        }
        while (list2 != nullptr)
        {
            current->next = list2;
            list2 = list2->next;
            current = current->next;
        }
        return dummy->next;
    }
};