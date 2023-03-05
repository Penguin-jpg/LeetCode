#include <vector>
using namespace std;

/**
 * 參考解答: 在演算法的時候有學過 prune-and-search，該演算法能在 worst case O(n)
 * 的情況下找到第 k小的元素，但根據這篇文章((網址附在下面)的分析，在面試時不適合
 * 用這方法， 因為寫起來非常麻煩，理論上也不會有人預期你用這樣的方法，但我們可以
 * 改成使用 quick select 來解，該演算法的 average case 是 O(n)，基本上能滿足
 * 絕大多數情況，其概念有點類似簡化版的 prune-and-search + quick sort 分割：
 *      1. 透過 partition 找 pivot index(和 quick sort 的步驟相同)
 *      2. 做完 partition 後原本的陣列可切為三份：
 *         1. 小於 pivot (s1)
 *         2. 等於 pivot (s2)
 *         3. 大於 pivot (s3)
 *      3. 分成三種情況討論：
 *         1. 若 k<=s1.size() -> 第 k 小的數在 s1 中 -> 對 s1 做 quick selection
 *         2. 若 k>s1.size()+s2.size() -> 第 k 小的數在 s3 中 -> 對 s3 做 quick selection
 *         3. 上述兩者都不符合的話就代表第 k 小的數在 s2 中
 * 上面雖然是用找第 k 小當做例子，但找第 k 大的原理一模一樣，只是比較時必須要和
 * nums.size()-k 進行比較，簡單來說就是從後面看回來，才是找第 k 大的元素
 * (https://leetcode.com/problems/kth-largest-element-in-an-array/solutions/1019513/python-quickselect-average-o-n-explained/)
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }

    int partition(vector<int> &nums, int left, int right)
    {
        int pivot = nums[right];
        int pivotIndex = left;
        for (int i = left; i <= right; i++)
        {
            if (nums[i] < pivot)
            {
                swap(nums[i], nums[pivotIndex]);
                pivotIndex++;
            }
        }
        swap(nums[right], nums[pivotIndex]);
        return pivotIndex;
    }

    int quickSelect(vector<int> &nums, int left, int right, int k)
    {
        if (left == right)
        {
            return nums[left];
        }
        int pivotIndex = partition(nums, left, right);
        if (nums.size() - k == pivotIndex) // target in s2 (equal to pivot)
        {
            return nums[pivotIndex];
        }
        else if (nums.size() - k < pivotIndex) // target in s1 (less than pivot)
        {
            return quickSelect(nums, left, pivotIndex - 1, k);
        }
        else // target in s3 (larger than pivot)
        {
            return quickSelect(nums, pivotIndex + 1, right, k);
        }
    }
};