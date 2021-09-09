class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        /*
            我的方法1
            時間複雜度O(nlog(n))(set插入複雜度log(n))、空間複雜度O(n)
            使用unordered_map+set
        */

        if (arr.size() == 0)
        {
            return arr;
        }

        set<int> nums;
        unordered_map<int, int> table;
        int rank = 1;

        for (int i = 0; i < arr.size(); i++)
        {
            nums.insert(arr[i]);
        }

        for (auto &it : nums)
        {
            table[it] = rank;
            rank++;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = table[arr[i]];
        }

        return arr;
    }
};