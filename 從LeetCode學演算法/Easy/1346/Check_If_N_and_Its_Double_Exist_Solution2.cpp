class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        /*
            參考的方法
            時間複雜度O(n)、空間複雜度O(n)
            檢查自己是否在set裡(代表自己是別人的2倍或1/2倍)，有就回傳true，
            如果沒有，就將自己的2倍和1/2倍(要能整除，乘兩倍後不會有奇數)加到set，
            全部檢查完都沒有就回傳false
        */

        unordered_set<int> nums;

        for (int i = 0; i < arr.size(); i++)
        {
            if (nums.count(arr[i]))
            {
                return true;
            }
            else
            {
                nums.insert(arr[i] * 2);
                if (arr[i] % 2 == 0)
                {
                    nums.insert(arr[i] / 2);
                }
            }
        }

        return false;
    }
};