class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        /*
            參考的方法
            時間複雜度O(nlog(n))、空間複雜度O(n)
        */

        if (arr.size() == 0)
        {
            return arr;
        }

        unordered_map<int, int> table;
        vector<int> sorted = arr;
        int rank = 1;
        sort(sorted.begin(), sorted.end());

        for (int i = 0; i < sorted.size(); i++)
        {
            if (table.count(sorted[i]) == 0)
            {
                table[sorted[i]] = rank;
                rank++;
            }
        }

        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = table[arr[i]];
        }

        return arr;
    }
};