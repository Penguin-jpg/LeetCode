#include <vector>
using namespace std;

/**
 * 參考解答: 題目問的是找出對所有nums[i]來說在他右邊且比他更小的數有幾個，也就是
 * 我們得選定一個左邊的數，並和其右邊的陣列部分進行比較，最直接的方法需要
 * O(n^2)，但仔細觀察可以發現這樣的過程其實被包含在merge sort內，也就是如果我們
 * 在做 merge sort的過程中同時紀錄右邊比左邊大的數量，就能夠在O(nlogn)內做完，詳
 * 細流程與技巧可以看程式註解或以下連結：
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/solutions/445769/merge-sort-clear-simple-explanation-with-examples-o-n-lg-n/
 * 時間: O(nlogn), 空間: O(n)
 */

// utility class for wrapping value and index
struct ValWithIndex
{
    int val;
    int index;
};

class Solution
{
  public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<ValWithIndex> vals(nums.size());
        vector<int> counters(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            vals[i] = ValWithIndex{nums[i], i};
        }
        mergeSort(vals, 0, nums.size() - 1, counters);
        return counters;
    }

    // just normal merge sort
    void mergeSort(vector<ValWithIndex> &vals, int left, int right, vector<int> &counters)
    {
        if (left < right)
        {
            int mid = (left + right) / 2;
            mergeSort(vals, left, mid, counters);
            mergeSort(vals, mid + 1, right, counters);
            mergeAndCount(vals, left, mid, right, counters);
        }
    }

    // do merge and also counting smaller numbers
    void mergeAndCount(vector<ValWithIndex> &vals, int left, int mid, int right, vector<int> &counters)
    {
        vector<ValWithIndex> merged(right - left + 1); // store merged results
        int mergedIndex = 0;
        // current number of elements in the left sub-array [left,mid] that are smaller
        // than right sub-array [mid+1,right] (i will call it "k" later for convenience)
        int currentNumElementsInRightArraySmallerThanLeftArray = 0;
        int i = left, j = mid + 1; // two pointers
        while (i <= mid && j <= right)
        {
            // if number in left sub-array is bigger than number in right sub-array,
            // then "k" should increment (it means that there is a number in
            // right sub-array is smaller than left sub-array)
            if (vals[i].val > vals[j].val)
            {
                currentNumElementsInRightArraySmallerThanLeftArray++;
                merged[mergedIndex] = vals[j];
                j++;
            }
            else // number in left sub-array is smaller than or equal to number in right sub-array
            {
                // it means that for vals[i], it can find "k" smaller numbers in right sub-array
                counters[vals[i].index] += currentNumElementsInRightArraySmallerThanLeftArray;
                merged[mergedIndex] = vals[i];
                i++;
            }
            mergedIndex++;
        }

        // append remaining elements in left sub-array
        while (i <= mid)
        {
            // every remaing left elements will be bigger than all numbers in right sub-array
            counters[vals[i].index] += currentNumElementsInRightArraySmallerThanLeftArray;
            merged[mergedIndex] = vals[i];
            i++, mergedIndex++;
        }

        // append remaining elements in right sub-array
        while (j <= right)
        {
            merged[mergedIndex] = vals[j];
            j++, mergedIndex++;
        }

        // copy values back to original array
        for (int i = left, j = 0; i <= right; i++, j++)
        {
            vals[i] = merged[j];
        }
    }
};