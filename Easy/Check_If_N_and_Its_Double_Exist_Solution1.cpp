class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        /*
            我的方法1
            時間複雜度O(n^2)、空間複雜度O(1)
            two pointers
        */

        for (int i = 0; i < arr.size() - 1; i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[i] == arr[j] * 2 || arr[j] == arr[i] * 2)
                {
                    return true;
                }
            }
        }

        return false;
    }
};