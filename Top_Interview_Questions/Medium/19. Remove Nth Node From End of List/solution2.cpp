/**
 * 想法: 先 reverse 一次，從尾巴開始找，找完之後再 reverse 回來
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *current = reverse(head);
        n--; // to index
        if (n == 0)
        {
            return reverse(head->next);
        }
        ListNode *previous = nullptr, *next = current, *dummy = current;
        int counter = 0;
        while (current != nullptr)
        {
            next = current->next;
            if (counter == n)
            {
                previous->next = next;
                break;
            }
            previous = current;
            current = next;
            counter++;
        }
        return reverse(dummy);
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *previous = nullptr, *current = head, *next = head;
        while (current != nullptr)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        return current;
    }

    void traversal(ListNode *head)
    {
        ListNode *current = head;
        while (current != nullptr)
        {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
};