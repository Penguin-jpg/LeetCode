class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        /*
            參考的方法
            時間複雜度O(n^2)、空間複雜度O(n)
        */

        vector<int> results;
        sort(nums.begin(), nums.end()); //先排序可以確定如果nums[i]被nums[j]整除，則整個子集合的數都能整除nums[j]

        vector<int> dp(nums.size(), 1);         //包括nums[i]在內的最大LDS長度
        vector<int> lastIndex(nums.size(), -1); //nums[i]的上一個index是誰
        int maxIndex = 0;                       //紀錄最大長度的index
        int maxDp = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                //如果[...,nums[j],nums[i]]長度大於[...,nums[i]]的長度，則更新長度
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    lastIndex[i] = j;
                }
            }

            //紀錄最大長度的index
            if (dp[i] > maxDp)
            {
                maxDp = dp[i];
                maxIndex = i;
            }
        }

        //從最大長度那個開始加往回找
        for (int i = maxIndex; i != -1; i = lastIndex[i])
        {
            results.push_back(nums[i]);
        }

        return results;
    }
};