#include <vector>
using namespace std;

/**
 * 想法: 用 quick sort
 * 時間: O(nlogn), 空間: O(1)
 */

class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
    }

    int partition(vector<int> &nums, int left, int right)
    {
        int pivot = nums[right]; // always use last one as pivot
        int pivotPos = left;     // pivot position after swapping
        for (int i = left; i < right; i++)
        {
            if (nums[i] < pivot) // if nums[i] is less than pivot, swap it with current pivot position
            {
                swap(nums[i], nums[pivotPos]);
                pivotPos++;
            }
        }
        swap(nums[right], nums[pivotPos]); // swap pivot to the position it should be
        return pivotPos;
    }

    void quickSort(vector<int> &nums, int left, int right)
    {
        if (left < right)
        {
            int pivot = partition(nums, left, right);
            quickSort(nums, left, pivot - 1); // since pivot is sorted so don't include pivot
            quickSort(nums, pivot + 1, right);
        }
    }
};