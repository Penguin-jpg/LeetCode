#include <vector>
using namespace std;

/**
 * 想法: 透過 two pointers，從 i=0, j=s.size()-1 開始，每次都交換 i,j，並將 i++,
 * j--，直到 i>j
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    void reverseString(vector<char> &s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};

// another way
class Solution
{
  public:
    void reverseString(vector<char> &s)
    {
        int size = s.size();
        for (int i = 0; i < size / 2; i++)
        {
            swap(s[i], s[size - i - 1]);
        }
    }
};