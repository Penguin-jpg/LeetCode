class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        /*
            我的方法2
            時間複雜度O(nlog(n))(map插入複雜度log(n))、空間複雜度O(n)
            使用map，速度會比方法1慢，但空間消耗較少
        */

        if (arr.size() == 0)
        {
            return arr;
        }

        map<int, int> table;
        int rank = 1;

        for (int i = 0; i < arr.size(); i++)
        {
            table[arr[i]] = -1;
        }

        for (auto &it : table)
        {
            table[it.first] = rank;
            rank++;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = table[arr[i]];
        }

        return arr;
    }
};